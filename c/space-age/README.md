# Ère spatiale

Bienvenue dans l'exercice Ère spatiale, sur le parcours C d'Exercism.
Si tu as besoin d'aide pour exécuter les tests ou soumettre ton code, consulte `HELP.md`.

## Introduction

Nous sommes en 2525 et tu viens de te lancer dans un voyage pour visiter toutes les planètes du système solaire (Mercure, Vénus, la Terre, Mars, Jupiter, Saturne, Uranus et Neptune).
La première escale est Mercure, où la douane t'oblige à remplir un formulaire (la bureaucratie n'est visiblement _pas_ propre à la Terre).
Alors que tu tends le formulaire à l'agent des douanes, il l'examine et fronce les sourcils.
« Tu t'attends _vraiment_ à ce que je croie que tu n'as que 50 ans ? Tu dois plutôt avoir dans les 200 ans ! »

Amusé, tu attends que l'agent des douanes éclate de rire, mais il a l'air on ne peut plus sérieux.
Tu comprends alors que tu as indiqué ton âge en _années terrestres_, alors que l'agent l'attendait en _années mercuriennes_ !
Comme la période orbitale de Mercure autour du soleil est nettement plus courte que celle de la Terre, tu es en réalité bien plus âgé en années mercuriennes.
Après quelques calculs rapides, tu parviens à donner ton âge en années mercuriennes.
L'agent des douanes sourit, satisfait, et te fait signe de passer.
Tu prends mentalement note de pré-calculer ton âge sur chaque planète _avant_ les prochains contrôles douaniers, pour éviter ce genre de méprise.

~~~~exercism/note
Si tu te demandes pourquoi Pluton n'a pas été retenue, va regarder [cette vidéo YouTube][pluto-video].

[pluto-video]: https://www.youtube.com/watch?v=Z_2gbGXzFbs
~~~~

## Instructions

À partir d'un âge en secondes, calcule quel âge aurait quelqu'un sur une planète de notre système solaire.

Une année terrestre équivaut à 365,25 jours terrestres, soit 31 557 600 secondes.
Si on te disait que quelqu'un a 1 000 000 000 de secondes, son âge serait de 31,69 années terrestres.

Pour les autres planètes, tu dois tenir compte de leur période orbitale exprimée en années terrestres :

| Planète | Période orbitale en années terrestres |
| ------- | ------------------------------------- |
| Mercure | 0.2408467                             |
| Vénus   | 0.61519726                            |
| Terre   | 1.0                                   |
| Mars    | 1.8808158                             |
| Jupiter | 11.862615                             |
| Saturne | 29.447498                             |
| Uranus  | 84.016846                             |
| Neptune | 164.79132                             |

~~~~exercism/note
La durée réelle d'une orbite complète de la Terre autour du Soleil est plus proche de 365,256 jours (1 année sidérale).
Le calendrier grégorien compte, en moyenne, 365,2425 jours.
Sans être tout à fait exacte, la valeur 365,25 est celle utilisée dans cet exercice.
Voir [Année sur Wikipédia][year] pour découvrir d'autres façons de mesurer une année.

[year]: https://en.wikipedia.org/wiki/Year#Summary
~~~~

## Source

### Created by

- @Guntau

### Contributed to by

- @bcc32
- @Gamecock
- @h-3-0
- @patricksjackson
- @QLaille
- @ryanplusplus
- @wolf99

### Based on

Partially inspired by Chapter 1 in Chris Pine's online Learn to Program tutorial. - https://pine.fm/LearnToProgram/chap_01.html