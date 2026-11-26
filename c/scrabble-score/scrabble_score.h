#ifndef SCRABBLE_SCORE_H
# define SCRABBLE_SCORE_H

# include <stdint.h>

typedef struct {
	char	*letters;
	int		value;
}	scoring_t;

unsigned int score(const char *word);

#endif
