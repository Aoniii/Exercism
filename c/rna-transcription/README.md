# Transcription d'ARN

Bienvenue dans l'exercice Transcription d'ARN, sur le parcours C d'Exercism.
Si tu as besoin d'aide pour exécuter les tests ou soumettre ton code, consulte `HELP.md`.

## Introduction

Tu travailles pour une entreprise de bio-ingénierie spécialisée dans le développement de solutions thérapeutiques.

Ton équipe vient de se voir confier un nouveau projet : développer une thérapie ciblée contre un type rare de cancer.

~~~~exercism/note
Tout cela est très compliqué, mais l'idée de base est que, parfois, le corps des gens produit trop d'une protéine donnée.
Cela peut semer la pagaille en tout genre.

Mais si tu parviens à créer une molécule très spécifique (appelée micro-ARN), elle peut empêcher la production de cette protéine.

Cette technique s'appelle l'[interférence par ARN][rnai].

[rnai]: https://admin.acceleratingscience.com/ask-a-scientist/what-is-rnai/
~~~~

## Instructions

Ton objectif est de déterminer le complément ARN d'une séquence d'ADN donnée.

Les brins d'ADN et d'ARN sont tous deux constitués d'une séquence de nucléotides.

Les quatre nucléotides présents dans l'ADN sont l'adénine (**A**), la cytosine (**C**), la guanine (**G**) et la thymine (**T**).

Les quatre nucléotides présents dans l'ARN sont l'adénine (**A**), la cytosine (**C**), la guanine (**G**) et l'uracile (**U**).

À partir d'un brin d'ADN, le brin d'ARN transcrit se forme en remplaçant chaque nucléotide par son complément :

- `G` -> `C`
- `C` -> `G`
- `T` -> `A`
- `A` -> `U`

~~~~exercism/note
Si tu veux voir comment les entrées et les sorties sont structurées, jette un œil aux exemples dans la suite de tests.
~~~~

## Source

### Contributed to by

- @bcc32
- @Gamecock
- @gea-migration
- @h-3-0
- @patricksjackson
- @QLaille
- @RealBarrettBrown
- @ryanplusplus
- @sjwarner
- @wolf99

### Based on

Hyperphysics - https://web.archive.org/web/20220408112140/http://hyperphysics.phy-astr.gsu.edu/hbase/Organic/transcription.html