//
// Created by mateu on 3/22/2021.
//

#ifndef GAME_OF_LIFE_GAMEENGINE_H
#define GAME_OF_LIFE_GAMEENGINE_H

/// \brief Base class for custom game engines
class GameEngine {
protected:

    /// \brief Config for game engines
    struct Config {
        int framerate;
    } current_config_;

    /// We dont wanna allow copying our game engine
    GameEngine() = delete;

    /// We dont wanna allow copying our game engine
    GameEngine(const GameEngine &) = delete;

    const GameEngine &operator=(const GameEngine &) = delete;

    /// \brief when we create a GameEngine we always need to give it a config
    explicit GameEngine(const GameEngine::Config &config) :
            current_config_(config) {};

    /// \brief game engine will start working
    virtual void start_engine() final;

    /// \brief This function is called on game start
    virtual void on_start() = 0;

    /// \brief This function will be invoked on every world tick
    virtual void on_tick() = 0;

    /// \brief This function is called when the game ends
    virtual void on_end() = 0;

    virtual ~GameEngine() = default;

protected:
    /// \brief start main game loop - now every frame on_tick() will be called
    void start_game_loop();

    /// \brief stopping the game loop - the on_end() will be called next
    void stop_game_loop();

private:
    /// \brief  engine logic happens here
    void main();
};

void GameEngine::start_engine() {

}


#endif //GAME_OF_LIFE_GAMEENGINE_H
