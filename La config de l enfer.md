# TP1 MiniJava

### Le  10/02/2026

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


Après on a rajouté OpGt dns TMJ et LMJ

...


On a modifié plein de fichiers pour ajouter le support de GT, et on a rajouté un test TestGt.java qui utilise GT, et qui est dans test/good, et qui passe aussi.

Et après tout ça, on peut make, et on peut faire 

    test/test.sh -a

