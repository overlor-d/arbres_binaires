# Makefile project

Ce projet vise a creer une makefile qui est importable directement dans vos projet avec la commande 

    git submodule add git@github.com:overlor-d/makefile.git ./

## Structure du Projet

Pour faire en sorte que ce makefile soit compatible avec ce projet il faudra remplir le fichier `var.mk`

## Compilation

Pour compiler le projet, les commandes suivantes sont disponibles :

- **`make all`** : Compile les bibliothèques statiques et partagées.
- **`make static`** : Compile uniquement la bibliothèque statique.
- **`make shared`** : Compile uniquement la bibliothèque partagée.
- **`make clean`** : Supprime les fichiers objets et les bibliothèques.
- **`make dist`** : Crée une archive du projet.
- **`make distclean`** : Supprime les fichiers objets, les bibliothèques et l'archive du projet.
- **`make check`** : Compile le projet et exécute les tests.

### Dépendances

Ce projet nécessite un compilateur C (comme gcc) et les outils standard de build Unix/Linux (`make`, `ar`, etc.).

### Usage

Après avoir compilé le projet, vous pouvez :

- Inclure la bibliothèque statique `$(NOM_PROJ).a` ou la bibliothèque partagée `$(NOM_PROJ).so` dans vos projets C.
- Utiliser `make check` pour exécuter les tests et vérifier l'intégrité des bibliothèques.

---

Inclus `Makefile.rules` pour les règles spécifiques et les configurations additionnelles nécessaires à la compilation du projet.
