# Attaque de la dame

Bienvenue dans l'exercice Attaque de la dame, sur le parcours C d'Exercism.
Si tu as besoin d'aide pour exécuter les tests ou soumettre ton code, consulte `HELP.md`.

## Instructions

À partir de la position de deux dames sur un échiquier, indique si elles sont placées de manière à pouvoir s'attaquer l'une l'autre.

Au jeu d'échecs, une dame peut attaquer les pièces qui se trouvent sur la même rangée, la même colonne ou la même diagonale.

On peut représenter un échiquier par un tableau de 8 par 8.

Ainsi, si on te dit que la dame blanche se trouve en `c5` (colonne 2, rangée 3, en comptant à partir de zéro) et la dame noire en `f2` (colonne 5, rangée 6, en comptant à partir de zéro), tu sais alors que la disposition est la suivante :­

![Un échiquier avec deux dames. Des flèches partant de la dame en c5 indiquent les directions de prise possibles le long des colonnes, des rangées et des diagonales.](https://assets.exercism.org/images/exercises/queen-attack/queen-capture.svg)

Tu peux aussi déterminer si les dames peuvent s'attaquer l'une l'autre.
Dans ce cas, la réponse serait oui, elles le peuvent, car les deux pièces partagent une diagonale.

## Crédits

L'image de l'échiquier a été réalisée par [habere-et-dispertire][habere-et-dispertire] avec LaTeX et le [paquet chessboard][chessboard-package] d'Ulrike Fischer.

[habere-et-dispertire]: https://exercism.org/profiles/habere-et-dispertire
[chessboard-package]: https://github.com/u-fischer/chessboard

## Source

### Created by

- @RealBarrettBrown

### Contributed to by

- @bcc32
- @h-3-0
- @patricksjackson
- @QLaille
- @ryanplusplus
- @wolf99

### Based on

J Dalbey's Programming Practice problems - https://users.csc.calpoly.edu/~jdalbey/103/Projects/ProgrammingPractice.html