# TP1: Chemins de Dyck


## Description

Projet(suite) d'introduction au langage C. Ce projet execute la lecture d'un fichier comme argument et fait l'affichage d'un mot caché à l'intérieur de ce fichier.

Le fichier lu sera passé comme argument et traité ensuite.
La redirection n'est pas supportée.

*Fichier `Makefile:`*
Il contient la construction de chaque commande make (compile, link, test et plus). C'est-à-dire leur cible et leurs dépendences pour l'exécution correctet la compilation finale de l'executable

*Commandes make et leur rôle:*

* `make:` Compile le fichier `motcache.c`.
* `make link:` Debut du programme, execute la commande `compile`.
* `make compile:` Execute la compilation générale avec toutes ses dependances \*.o.
* `make test:` Execute les tests du fichier `check.bats` sur `motcache`. Ou Compile 
`motcache.c:` s'il ne l'est pas encore et execute les tests par la suite.
* `make html:` Convertit `README.md` en fichier html.
* `make clean:` Efface les fichiers `\*.o` et/ou `\*.html` ainsi que tout autre type de fichier
ce trouvant dans le fichier `gitignore`.

Ce travail est realisé en vue du travail TP2 dans le cadre du cours Construction et
maintenance de logiciels INF3135. Cours donné par Serge Dogny à l'Université de Québec à Montreal.

Lien vers le [README du travail](https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/inf3135-hiv2022-tp2/-/blob/master/README.md).

***Tous les tests ont étés réussis sur ma machine comme sur le serveur Labunix de l'UQAM***

## Auteur

Renzo Arturo Salcedo (SALR02089408).

## Fonctionnement

Pour commencer, compilez le fichier `motdedyck.c` avec la commande:
```sh
$ make
```
Vous obtiendrez l'exécutable `motcache`. 

Par la suite, vous executez l'executable avec le fichier commme argument (i.e `./motcache entree.txt`)

Voici les regles à respecter pour vos entrées:

* Le fichier doit exister.
* Un seul argument (le fichier à lire) peut être utilisé

Voici une suite de tests valides comme exemple (stdin sur la ligne de commande commmearg):
```sh
$  make 
$ ./motcache entree.txt
$ ./motdedyck mandoline.txt
$ ./motdedyck venise.txt
```

## Tests

Pour lancer les tests ecrivez `make test` sur la ligne de commande.
Vous obtiendrez les résultats du fichier `check.bats`, qui vous informera de vos tests réussis et ceux échoués.

Si vous n'avez pas le fichier `motdedyck` avant de lancer cette commande, la 
commande `link` sera lancée en parellèle suivie de toutes ses dependances et 
un fichier `motcache` sera créé automatiquement. 
```sh
$ make test
``` 
Cette commande exécute les tests du fichier `check.bats` sur `motcache`. Ou Compile 
`motcache.c` s'il ne l'est pas encore et execute les tests par la suite.

## Dépendances

* [GCC](https://gcc.gnu.org/).
* [Bats](https://github.com/bats-core/bats-core).
* [Pandoc](https://pandoc.org/).
* [Make](https://www.gnu.org/software/make/).
* [Git](https://git-scm.com/).
 

## Références

De facon générale le site [Stackoverflow](https://stackoverflow.com/) a été utilisé pour la 
compréhension de certaines fonctions. 
Des discussions sur le mattermost du cours ont aussi servis d'inspiraton dans ce travail.

## État du projet

* [X] Le nom du dépôt GitLab est exactement `inf3135-hiv2022-tp2` (Pénalité de
  **20%**).
* [X] L'URL du dépôt GitLab est exactement `https://gitlab.info.uqam.ca/utilisateur/inf3135-hiv2022-tp2`
https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/inf3135-hiv2022-tp2
  (Pénalité de **20%**).
* [X] L'utilisateur `dogny_g` et les correcteurs ont accès au projet en mode *Developer*
  (Pénalité de **20%**).
* [X] Le dépôt GitLab est privé (Pénalité de **20%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `compile`, `link`, `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [X] L'indentation doit être de 3 espaces. Aucune tabulation n'est permise dans l'indentation.
* [X] L'en-tête du fichier main est documentée.
* [X] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [X] Le programme ne contient pas de valeurs magiques.
 
