# Help

## Exécute les tests

Fais en sorte que le premier test se compile, se lie et passe, en suivant les [trois règles du développement piloté par les tests][3-tdd-rules].

Le _makefile_ fourni permet de créer et de lancer les tests à l'aide de la tâche `test`.

```console
$ make test
```

Crée uniquement les fonctions nécessaires pour faire disparaître les erreurs du compilateur et faire échouer le test.
Écris ensuite juste assez de code pour que le test passe.
Une fois cela fait, passe au test suivant.

Au fil des tests, prends le temps de réécrire ton implémentation pour la rendre plus lisible et plus expressive, puis passe au test suivant.

Essaie d'utiliser les fonctionnalités standard du C99 plutôt que d'écrire à la main tes propres algorithmes ou outils de bas niveau.

## Vérifie les fuites de mémoire

Le _makefile_ fournit aussi une compilation qui vérifie quelques erreurs courantes liées aux fuites de mémoire et aux accès hors limites dans les tableaux.
Pour lancer ces vérifications, utilise la commande suivante dans le terminal :

```console
$ make memcheck
```

[3-tdd-rules]: https://blog.cleancoder.com/uncle-bob/2014/12/17/TheCyclesOfTDD.html

## Soumets ta solution

Tu peux soumettre ta solution avec la commande `exercism submit leap.c leap.h`.
Cette commande enverra ta solution sur le site d'Exercism et affichera l'URL de la page de la solution.

Il est possible de soumettre une solution incomplète, ce qui te permet de :

- Voir comment d'autres personnes ont résolu l'exercice
- Demander l'aide d'un mentor

## Besoin d'aide ?

Si tu souhaites de l'aide pour résoudre l'exercice, consulte les pages suivantes :

- La [documentation du parcours C](https://exercism.org/docs/tracks/c)
- La [catégorie de programmation du parcours C sur le forum](https://forum.exercism.org/c/programming/c)
- La [catégorie de programmation d'Exercism sur le forum](https://forum.exercism.org/c/programming/5)
- Les [questions fréquentes](https://exercism.org/docs/using/faqs)

Si ces ressources ne suffisent pas, tu peux soumettre ta solution (incomplète) pour demander un mentorat.

Assure-toi d'avoir lu la [documentation propre au parcours C][c-track] sur le site d'Exercism.
Elle couvre les informations de base pour mettre en place l'environnement de développement attendu par les exercices.

## Ressources

Pour obtenir de l'aide en cas de difficulté, tu peux utiliser les ressources suivantes :

- [StackOverflow][] permet de chercher ton problème et de voir s'il a déjà reçu une réponse. Tu peux aussi poser des questions et répondre à celles des autres.
- [CPPReference][] permet de consulter des informations sur les concepts du C, les opérateurs, les types, les fonctions de la bibliothèque standard, et bien plus encore.
- [TutorialsPoint][] propose un contenu similaire à CPPReference dans sa section consacrée à la programmation en C.
- [The C Programming][K&R], le livre de K&R, est la source originale du langage et reste utile aujourd'hui.

[c-track]: https://exercism.org/docs/tracks/c
[stackoverflow]: http://stackoverflow.com/questions/tagged/c
[cppreference]: https://en.cppreference.com/c
[tutorialspoint]: https://www.tutorialspoint.com/cprogramming/
[K&R]: https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/