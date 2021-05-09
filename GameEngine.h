//
// Created by mateu on 3/22/2021.
//

#ifndef GAME_OF_LIFE_GAMEENGINE_H
#define GAME_OF_LIFE_GAMEENGINE_H

#include "Renderer.h"
#include <chrono>
#include <thread>

/// \brief Base class for custom game engines
class GameEngine {

public:
    /// We dont wanna allow creating GameEngine without configuration
    GameEngine() = delete;

    /// We dont wanna allow copying our game engine
    GameEngine(const GameEngine &) = delete;

    GameEngine &operator=(const GameEngine &) = delete;

    /// \brief Config for game engines
    struct Config {
        int framerate;
        Renderer *renderer;
    } current_config_;

protected:

    /// \brief when we create a GameEngine we always need to give it a config
    explicit GameEngine(const GameEngine::Config &config) :
            current_config_(config),
            renderer_(config.renderer),
            running_(false) {};

    /// \brief game engine will start working
    virtual void start_engine() final {
        on_start();
        while (running_) {
            // we are measuring the time before the work in the frame
            auto start = std::chrono::high_resolution_clock::now();
            on_tick();
            // we are measuring the time after the work in the frame
            auto stop = std::chrono::high_resolution_clock::now();
            // how long should the frame take
            auto target_frame_time = std::chrono::seconds(1 / current_config_.framerate);
            // how long it took
            auto current_frame_time = start - stop;
            // sleep for the difference between target and real time
            std::this_thread::sleep_for(target_frame_time - current_frame_time);
        }
        on_end();
    };

    /// \brief This function is called on game start should be overrided by the deriving class
    virtual void on_start() = 0;

    /// \brief This function will be invoked on every world tick should be ovverided by the derriving class
    virtual void on_tick() = 0;

    /// \brief This function is called when the game ends should be ovverided by the derriving class
    virtual void on_end() = 0;

    virtual ~GameEngine() { delete renderer_; }

protected:
    /// \brief start main game loop - now every frame on_tick() will be called
    void start_game_loop() { running_ = true; }

    /// \brief stopping the game loop - the on_end() will be called next
    void stop_game_loop() { running_ = false; }

    Renderer *renderer_;

private:
    bool running_;

};


#endif //GAME_OF_LIFE_GAMEENGINE_H
