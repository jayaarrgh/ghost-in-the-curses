#include <ncurses.h>
#include "screen.h"
#include "input.h"
#include "discourse.h"


/* https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
/* https://www.youtube.com/watch?v=4TRUf75mJNU&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=12 */


int main() {
	initscr();

	Screen screen;
	/* screen.IntroScreen(); */
	Discourse disc;	
	screen.Output(disc.GetSequentialSentence());
	// game loop
	bool exit = false;
	while (true) {
		// get input and refresh input window
		std::string input = screen.GetInput();
		
		/* exit = handleQuit(input, screen); */
		if (handleQuit(input, screen)) break;
		screen.Output(disc.GetSequentialSentence());
	}

	endwin();
	return 0;
}
