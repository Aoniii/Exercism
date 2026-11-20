# Hamming

Bienvenue dans l'exercice Hamming, sur le parcours C d'Exercism.
Si tu as besoin d'aide pour exécuter les tests ou soumettre ton code, consulte `HELP.md`.

## Introduction

Ton corps est constitué de cellules qui contiennent de l'ADN.
Ces cellules s'usent régulièrement et doivent être remplacées, ce qu'elles font en se divisant en cellules filles.
En fait, en moyenne, le corps humain connaît environ 10 millions de milliards de divisions cellulaires au cours d'une vie !

Lorsque les cellules se divisent, leur ADN se réplique aussi.
Parfois, pendant ce processus, des erreurs se produisent et des fragments d'ADN isolés se retrouvent encodés avec une information incorrecte.
Si on compare deux brins d'ADN et qu'on compte les différences entre eux, on peut voir combien d'erreurs se sont produites.
C'est ce qu'on appelle la « distance de Hamming ».

La distance de Hamming est utile dans de nombreux domaines scientifiques, pas seulement en biologie, donc c'est une expression qu'il est bon de connaître :)

## Instructions

Calcule la distance de Hamming entre deux brins d'ADN.

On lit l'ADN à l'aide des lettres C, A, G et T.
Deux brins peuvent ressembler à ceci :

    GAGCCTACTAACGGGAT
    CATCGTAATGACGGCCT
    ^ ^ ^  ^ ^    ^^

Ils présentent 7 différences, donc la distance de Hamming est de 7.

## Notes d'implémentation

La distance de Hamming n'est définie que pour des séquences de même longueur, donc essayer de la calculer entre des séquences de longueurs différentes ne doit pas fonctionner.

## Source

### Created by

- @sunzenshen

### Contributed to by

- @bcc32
- @Gamecock
- @gea-migration
- @h-3-0
- @hintjens
- @JacobMikkelsen
- @kytrinyx
- @lpil
- @patricksjackson
- @QLaille
- @RealBarrettBrown
- @ryanplusplus
- @siebenschlaefer
- @sjwarner
- @wolf99

### Based on

The Calculating Point Mutations problem at Rosalind - https://rosalind.info/problems/hamm/