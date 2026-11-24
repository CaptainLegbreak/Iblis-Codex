#!/bin/bash
# cvslots.sh <root> <unitjsonbase> <FunctionDisplayName> : frame slots of locals from CodeView
O=$(python3 -c "import json;print(json.load(open('$1/out/obj/$2.json'))['obj'])")
llvm-readobj --codeview $1/out/$O > /tmp/cv_$$.txt 2>&1
n=$(grep -n "DisplayName: $3\$" /tmp/cv_$$.txt | head -1 | cut -d: -f1)
awk -v n=$n 'NR>n {print}' /tmp/cv_$$.txt | awk '/Kind: S_GPROC32|Kind: S_LPROC32/{exit} {print}' | grep -E "Kind: S_BPREL32|Offset: -|VarName|Kind: S_REGISTER|Register:" | paste -s -d' ' | sed 's/Kind: S_BPREL32 (0x110B)/\n/g; s/Kind: S_REGISTER (0x1106)/\nREG/g' | sed 's/Offset: //; s/VarName: //' | awk '{print $1, $2, $3, $4, $5}' | sort -n | paste -s -d','
rm -f /tmp/cv_$$.txt
