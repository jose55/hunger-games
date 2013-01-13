#include "ScheduledPlayer.h"
#include "Game.h"

using namespace HungerGames;

ScheduledPlayer::ScheduledPlayer(char name, Console::Color color, const char* eventsFilename):
    BasePlayer(name, color), events(eventsFilename) {
}

void ScheduledPlayer::update() {
    if (power > 0) {
        if (pGame->getTick() % MOVE_INTERVAL == 0) {
            setSquare(getNextSquare());
        }

        EventsFile::Event* ev = events.getEvent(pGame->getTick());
        if (ev) {
            for (int i = 0; i < ev->getNumActions(); i++) {
                doAction((Action) ev->getAction(i));
            }
        }
    }
}