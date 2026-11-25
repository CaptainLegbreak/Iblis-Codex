#!/usr/bin/env python3
"""Build tcspin/bin: a copy of the pinned SP1 toolchain whose c2.dll entry of the global register allocator's
driver (VA 0x10b0cf40, `sub esp, 0x18` = 83 EC 18) starts with `jmp $` (EB FE), so the compiler parks there and gdb
can attach. c2prio_gdb.py restores the two bytes in memory before any allocator code runs, so the emitted object is
the pinned compiler's (checked: identical .text). The pinned files themselves are only read.

usage: setup_tcspin.py PINNED_BIN_DIR   (the pinned SP1 bin/ folder; ~/.d2match.json 'cl' names it)
The copy goes to $C2DIAG_HOME/tcspin/bin (default ~/.d2match-c2diag), outside the repository.
"""
import hashlib, os, shutil, sys

C2_SHA256 = '497d1ffe57f75db8b458167bdea475f3962829e139b355a2672a4ef51c716413'   # config.json toolchain.c2_sha256
CL_SHA256 = '71c93ca5bddc9b2816d0e053cac2b952f926f6b9321fab6b1ab6e8603621324c'
PATCH_OFF = 0x10b0cf40 - 0x10b00000      # .text raw offset == RVA in this image


def sha(p):
    return hashlib.sha256(open(p, 'rb').read()).hexdigest()


def main():
    src = os.path.abspath(sys.argv[1])
    work = os.environ.get('C2DIAG_HOME', os.path.join(os.path.expanduser('~'), '.d2match-c2diag'))
    dst = os.path.join(work, 'tcspin', 'bin')   # outside the repo: the patched copy is never committed
    if sha(os.path.join(src, 'c2.dll')) != C2_SHA256 or sha(os.path.join(src, 'cl.exe')) != CL_SHA256:
        sys.exit('not the pinned SP1 toolchain (c2.dll / cl.exe hash mismatch)')
    if os.path.exists(dst):
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    for root, dirs, files in os.walk(dst):
        for f in files:
            os.chmod(os.path.join(root, f), 0o644)
    p = os.path.join(dst, 'c2.dll')
    d = bytearray(open(p, 'rb').read())
    assert d[PATCH_OFF:PATCH_OFF + 3] == b'\x83\xec\x18', 'unexpected bytes at the patch point'
    d[PATCH_OFF:PATCH_OFF + 2] = b'\xeb\xfe'
    open(p, 'wb').write(d)
    print('tcspin ready:', dst)


if __name__ == '__main__':
    main()
