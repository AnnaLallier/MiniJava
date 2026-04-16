# MiniJava Transpiler - 4INFO 2026

Du 10/02/2026 au 17/04/2026

https://github.com/AnnaLallier/MiniJava/

## Auteurs

- Anna LALLIER
- Maud RAMEL
- Pascal GARCIA (créateur du projet)

## Lancement

Compiler avec :

    make clean
    make 

(`make clean` n'est pas obligatoire, mais il est conseillé de l'utiliser pour être sûr que les modifications soient prises en compte)

Pour tester : 
    
    test/test.sh -a

Tester le C avec mini-java (exemples) :

    ./mini-java ./test/good/Ackermann.java
    ./mini-java ./test/good/TestEquals.java 


## Instructions

Listes de possibilités à ajouter :

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
    surcharge : changer le nom des fonctions pour rendre un nom unique
    sysout (fait)
    lambda
    return void pour les méthodes (fait)

    return (fait)
    break 
    continue


## Description

`mini-java` is an educational transpiler from [MiniJava](http://www.cambridge.org/resources/052182060X/), which is a subset of [Java](https://en.wikipedia.org/wiki/Java_%28programming_language%29),
to [C](https://en.wikipedia.org/wiki/C_%28programming_language%29).\
The construction of this transpiler is documented on [www.mrcoder.org](https://www.mrcoder.org/en/compiler/minijava/).

### Install Dependencies

#### Linux (Ubuntu)

```bash
sudo apt-get install ocaml opam
opam init -a -y
eval `opam config env`
opam switch -y 4.07.0
eval `opam config env`
opam install -y ocamlbuild ocamlfind menhir
```

#### Mac OS X

```bash
brew install gpatch m4 ocaml opam
opam init -a -y
eval `opam config env`
opam switch -y 4.07.0
eval `opam config env`
opam install -y ocamlbuild ocamlfind menhir
```

### Download, Compile and Run

Once you have the dependencies (see above), run the following commands in your terminal.

```bash
git clone --recurse-submodules https://github.com/lascar-pacagi/MiniJava.git
make
./mini-java file.java
./file
```

---

The default C compiler is `cc`. if you want to use another compiler, you should give the name of the compiler as follow.

```bash
./mini-java --c-compiler clang file.java
```

---

If you want to launch `mini-java` from any directory, you should give the path to the `tgc` directory.

```bash
./mini-java --tgc-path "path to tgc directory" file.java
```

---

If you want to use `mini-java` without a garbage collector, and so without dependencies to `tgc`, you can
checkout the version 1.0. In this version, the transpiler doesn't use a garbage collector and only produces
the generated C file.

```bash
git checkout v1.0
make
./mini-java file.java
gcc file.c -o file
./file
```

If you want to modify the version 1.0, you can create a new branch from version 1.0 (for example `from_v1.0`).

```bash
git checkout -b from_v1.0 v1.0
```

to go back to the version with a garbage collector do the following.

```bash
git checkout master
make
```

The branch `ast_typed` has an abstract syntax tree decorated with type information. This tree is produced by the typechecker and it can be useful if you want to augment `MiniJava`.



## Références utiles

https://introcs.cs.princeton.edu/java/11precedence/

https://docs.oracle.com/javase/specs/jls/se25/html/index.html

https://blog.paumard.org/cours/java/chap05-noms-operateurs-operateurs.html
