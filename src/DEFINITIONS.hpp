#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SPLASH_STATE_SHOW_TIME 1.5

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Content/splash.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Content/menu.png"
#define GAME_STATIC_BACKGROUND_FILEPATH "Content/backdrop.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Content/gameover.png"

#define MAIN_MENU_PLAY_BUTTON "Content/playbutton.png"
#define MAIN_MENU_CREDITS "Content/creditsbutton.png"
#define MAIN_MENU_ABOUT "Content/aboutbutton.png"

#define GAME_PLAYER "Content/playerspritesheet.png"
#define GAME_GROUND "Content/ground.png"
#define GAME_CLOUD "Content/cloud.png"
#define GAME_MOUNTAIN "Content/static mountain.png"
#define GAME_OBSTACLE1 "Content/tree trunk.png"
#define GAME_OBSTACLE2 "Content/rock.png"
#define GAME_OBSTACLE3 "Content/spikes.png"
#define FOREST_PATH "Content/forests.png"

#define STATE_PLAYING 95
#define STATE_PAUSED 94
#define STATE_DEAD 93

#define OBSTACLE_SPEED 290.0f
#define FOREST_SPEED 50.0f
#define OBSTACLE_FREQUENCY 3.0f

#define CLOUD_SPEED 25.0f
#define CLOUD_FREQUENCY 2.0f

#define RED_FRAME_1 "Content/frame1.png"
#define RED_FRAME_2 "Content/frame2.png"
#define RED_FRAME_3 "Content/frame3.png"
#define RED_FRAME_4 "Content/frame4.png"
#define RED_FRAME_5 "Content/frame5.png"
#define RED_FRAME_6 "Content/frame6.png"
#define RED_FRAME_7 "Content/frame7.png"
#define RED_FRAME_8 "Content/frame8.png"
#define RED_FRAME_9 "Content/frame9.png"
#define RED_FRAME_10 "Content/frame10.png"
#define RED_FRAME_11 "Content/frame11.png"
#define RED_FRAME_12 "Content/frame12.png"
#define RED_FRAME_13 "Content/frame13.png"
#define RED_FRAME_14 "Content/frame14.png"
#define RED_JUMP_1 "Content/jump1.png"
#define RED_JUMP_2 "Content/jump2.png"
#define RED_SLIDE_1 "Content/slide1.png"
#define RED_SLIDE_2 "Content/slide2.png"

#define ANIMATION_TIME .65f

#define RED_RUNNING 1
#define RED_JUMPING 2
#define RED_FALLING 3
#define RED_SLIDING 4

#define GRAVITY 96.5f
#define JUMP_SPEED 100.5f
#define JUMP_TIME 1.0f

enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};

#define GAME_OVER_TIME 100.0f

#define FONT_PATH "Content/Fipps-Regular.otf"
#define SCORING_PATH "Content/scoringBlock.png"

#define RUNNING_AUDIO "Content/run.ogg"
#define JUMPING_AUDIO "Content/jump.ogg"
#define DEATH_AUDIO "Content/gameover.ogg"
#define RUN_MUSIC_AUDIO "Content/bg.ogg"