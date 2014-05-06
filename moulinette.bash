#!/bin/bash

if [ $# == 0 ]; then
    echo "Rentrez en arguments des champions !"
    exit 1
fi

rm -f log log_final

if [ ! -f asm/asm ]; then
    echo "l'exécutable asm n'exite pas..."
    exit 1
fi

if [ ! -f champion/Asm ]; then
    echo "l'exécutable Asm n'exite pas..."
    exit 1
fi

if [ ! -f de_asm/de_asm ]; then
    echo "l'exécutable de_asm n'exite pas..."
    exit 1
fi

for fichier in "$@"
do
    path=$(echo -n "$fichier" | sed "s/\.s$/\.cor/")
    if [ "$path" == "$fichier" ]; then
	echo "$fichier" " : ce n'est pas un fichier s"
	exit 1
    fi
    asm=$(echo -n "$fichier" | sed "s/\.s$/_asm.cor/")
    ASM=$(echo -n "$fichier" | sed "s/\.s$/_ASM.cor/")
    de_asm=$(echo -n "$asm" | sed "s/\.cor$/\.s/")
    DE_ASM=$(echo -n "$ASM" | sed "s/\.cor$/\.s/")
    
    rm -f "$asm" "$ASM" "$de_asm" "$DE_ASM" > /dev/null 2>&1

    ./asm/asm "$fichier" > /dev/null 2>&1
    if [ $? != 0 ]; then
	echo "$fichier l'asm n'as pas put créer le cor FAILURE"
	exit 1
    fi
    mv "$path" "$asm" > /dev/null 2>&1

    ./champion/Asm "$fichier" > /dev/null 2>&1
    if [ $? != 0 ]; then
	echo "$fichier l'Asm n'as pas put créer le cor FAILURE"
	exit 1
    fi
    mv "$path" "$ASM"  > /dev/null 2>&1

    ./de_asm/de_asm "$asm" "$ASM" > /dev/null 2>&1
    if [ $? != 0 ]; then
	echo "$asm $ASM le de_asm n'as pas put créer les s FAILURE"
	exit 1
    fi

    echo -n "$fichier testing... "
    diff -sq "$asm" "$ASM" > log
    diff -sq "$de_asm" "$DE_ASM" >> log

    ./asm/asm "$de_asm" > /dev/null 2>&1
    if [ $? != 0 ]; then
	echo "$de_asm l'asm n'as pas put créer le cor FAILURE"
	exit 1
    fi

    ./champion/Asm "$DE_ASM" > /dev/null 2>&1
    if [ $? != 0 ]; then
	echo "$DE_ASM l'Asm n'as pas put créer le cor FAILURE"
	exit 1
    fi

    diff -sq "$de_asm" "$DE_ASM" >> log
    cat log >> log_final
    result=$(grep differ log)
    if [ ${#result} == 0 ]; then
	echo "SUCCESS"
    else
	echo "FAILURE"
	cat result
    fi
    
    rm -f "$asm" "$ASM" "$de_asm" "$DE_ASM" > /dev/null 2>&1
done

result=$(grep differ log_final)
if [ ${#result} == 0 ]; then
    echo "SUCCESS TOTAL"
else
    echo "FAILURE TOTAL"
fi

rm -f log log_final > /dev/null 2>&1

