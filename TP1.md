# TP1 MiniJava

### Le  10/02/2026

Environ 5 points au DS. Mieux vaut faire jusqu'à if sans else, chaînes de caractères, opérateurs associés, etc.

## Références

https://introcs.cs.princeton.edu/java/11precedence/

https://docs.oracle.com/javase/specs/jls/se25/html/index.html

https://blog.paumard.org/cours/java/chap05-noms-operateurs-operateurs.html

## La config de l'enfer

J'ai fork à partir de  https://github.com/lascar-pacagi/MiniJava

J'ai cloné mon fork, j'ai installé les dépendances, puis en branche ast_typed,  puis modifié la ligne 105 du fichier main.ml

      Unix.system(Printf.sprintf "%s %s -o %s -std=c99 -I%s %s/tgc.o"

Et après 

    rmdir tgc

Et 

    git clone https://github.com/orangeduck/tgc/tree/35207051557c79ea25942c021fb18856c72af8e3

Puis 

    test/test.sh -a

Et enfin on a du vert partout youpi

## Rajout de GT >

Après on a rajouté OpGt dns TMJ et LMJ

...


On a modifié plein de fichiers pour ajouter le support de GT, et on a rajouté un test TestGt.java qui utilise GT, et qui est dans test/good, et qui passe aussi.

A chaque fois, il faut modifier l'affichage dans printTMJ.ml, au début et dans les expressions plus bas également.

Ensuite make clean, make, et Ocaml ajoute des warning en fonction de ce qu'il faut corriger (ex, dans print_ast, )

_Sinon on peut commenter les lignes 99 à 101 de main.ml pour éviter de le faire :_

    Printf.fprintf output "/*\n";
    PrintTMJ.print_program output tmj;
    Printf.fprintf output "*/\n";

Et après tout ça, on peut make, et on peut faire 

    make
    
    test/test.sh -a


## Instructions

Liste de choses à faire : 

    > (fait)
    || (fait)
    ^ (fait)
    / (fait)
    & (fait)
    | (bitwise inclusive OR) (fait)
    ==  (utiliser compatible) (fait)
    if sans else (fait)
    for (fait)
    do ... while (fait)
    
    float (fait)
    string (fait)
    interface
    surcharge
    sysout
    lambda

    return 
    break 
    continue


## Ajout de ||

- LMJ : ajout de OpOr dans le type binop
- TMJ : ajout de OpOr dans le type binop
- parser.mly : ajout de OR dans token + priorités (en haut du fichier) + inline binop
- typechecking.ml : ajout de OpOr dans les expressions binaires, avec des types booléens
- lexer.mll : "||"      { OR }
- mj2.ml en dessous de binop2c
- Ajout de TestOr.java dans test/good, qui utilise ||

## Ajout de float

- parser.mly : ajout de FLOAT_CONST dans les tokens, et dans les expressions, et en typ
- typechecking.ml : je me suis arrêtée en ligne 210, mais il y a plein de choses...
- lexer.mll
float of string à utiliser

Dans typechecking, adapter OpDiv & OpMult d'une façon similaire à ce qu'on a fait pour les opérateurs bit à bit.

A chaque fois qu'on ajoute quelque chose, pour tester on fait

    make
    test/test.sh -a

Quand ça en marche pas, il est utile de faire 

    ./mini-java ./test/good/TestEquals.java 
    Fatal error: exception File "mj2c.ml", line 298, characters 2-7: Pattern matching failed