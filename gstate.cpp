#include "gstate.h"
#include "collider.h"


void GState::initTextures()
{
    if(!music.openFromFile("sound/Tristram.flac")){
        std::cerr<<"Music not loaded";
    }

    if(!texturesPlayer["PLAYER_NEUTRAL"].loadFromFile("images/paladin_neutral.png")){
        std::cout<<"player neutral texture rip"<<std::endl;
    }
    if(!texturesPlayer["PLAYER_RUN"].loadFromFile("images/paladin_run.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesPlayer["PLAYER_ATTACK"].loadFromFile("images/paladin_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!texturesEnemies["GOATMAN_NEUTRAL"].loadFromFile("images/goatman_neutral.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["GOATMAN_WALK"].loadFromFile("images/goatman_walk.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["GOATMAN_ATTACK"].loadFromFile("images/goatman_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["GOATMAN_DIE"].loadFromFile("images/goatman_die.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!texturesEnemies["SKELETON_NEUTRAL"].loadFromFile("images/skeleton_neutral.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["SKELETON_WALK"].loadFromFile("images/skeleton_walk.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["SKELETON_ATTACK"].loadFromFile("images/skeleton_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["SKELETON_DIE"].loadFromFile("images/skeleton_die.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!texturesEnemies["ANDARIEL_NEUTRAL"].loadFromFile("images/andariel_neutral.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["ANDARIEL_WALK"].loadFromFile("images/andariel_walk.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["ANDARIEL_ATTACK"].loadFromFile("images/andariel_attack.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }
    if(!texturesEnemies["ANDARIEL_DIE"].loadFromFile("images/andariel_die.png")){
        std::cout<<"player run texture rip"<<std::endl;
    }

    if(!mapTextures["LEVEL_1"].loadFromFile("images/town_floor.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_OBJ"].loadFromFile("images/town_objects.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_TREES"].loadFromFile("images/trees.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_1_ENTRY"].loadFromFile("images/entry.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_2_FLOOR"].loadFromFile("images/cathedral_floor.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_2_FLOOR2"].loadFromFile("images/cathedral_floor2.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!mapTextures["LEVEL_2_WALL"].loadFromFile("images/cathedral_wall.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["BLOOD_VESSEL"].loadFromFile("images/blood_vessel.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["FIRE_COLUMN"].loadFromFile("images/fire_column.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["COLUMN"].loadFromFile("images/column.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["ALTAR"].loadFromFile("images/altar.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["BENCH_1"].loadFromFile("images/bench1.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["BENCH_2"].loadFromFile("images/bench2.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["BENCH_3"].loadFromFile("images/bench3.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["BENCH_4"].loadFromFile("images/bench4.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["CANDLE_1"].loadFromFile("images/candle1.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["CANDLE_2"].loadFromFile("images/candle2.png")){
        std::cerr<<"Texture not loaded";
    }
    if(!objTextures["THRONE"].loadFromFile("images/throne.png")){
        std::cerr<<"Texture not loaded";
    }


    if(!textureWall.loadFromFile("images/wall.png")) {
        std::cerr << "Could not load wall" << std::endl;
    }
    textureWall.setRepeated(true);


}

void GState::initObjects()
{
    this->player=new Player(sf::Vector2f(1400.0f,1020.0f), texturesPlayer);
    this->playerGUI=new PlayerGUI(this->player);

    //enemies
    enemies.emplace_back(new Goatman(sf::Vector2f(1365.0f,3260.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(1518.0f,3130.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(1764.0f,3257.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(1813.0f,2990.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2149.0f,2971.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2026.0f,3256.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2499.0f,3013.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2319.0f,3230.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2583.0f,2315.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2323.0f,3463.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2214.0f,3647.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(1806.0f,3424.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2073.0f,2848.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2196.0f,2752.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2242.0f,2878.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2580.0f,2761.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2701.0f,2761.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2947.0f,2888.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2919.0f,3310.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2638.0f,3386.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2736.0f,3240.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3081.0f,3227.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(3307.0f,3141.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2449.0f,2629.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(2896.0f,2718.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3093.0f,2784.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3213.0f,2701.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(3397.0f,2886.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(3100.0f,3141.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3311.0f,3044.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3680.0f,2883.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(4002.0f,2861.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(3780.0f,3110.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(3839.0f,2964.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(4218.0f,3021.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(4173.0f,3162.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3116.0f,2533.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2503.0f,2537.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2410.0f,2228.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(2779.0f,2246.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3640.0f,2499.0f), texturesEnemies));
    enemies.emplace_back(new Skeleton(sf::Vector2f(3694.0f,2334.0f), texturesEnemies));
    enemies.emplace_back(new Goatman(sf::Vector2f(4052.0f,2368.0f), texturesEnemies));


    enemies.emplace_back(new Andariel(sf::Vector2f(4150.0f,2050.0f), texturesEnemies));




    for(auto &it:enemies){
        enemyGUI.emplace_back(new PlayerGUI(it,player));
    }

    //blood vessels
    objects.emplace_back(new Object(sf::Vector2f(3200.0f,2550.0f), objTextures,0));
    objects.emplace_back(new Object(sf::Vector2f(3330.0f,2610.0f), objTextures,0));
    objects.emplace_back(new Object(sf::Vector2f(2640.0f,2310.0f), objTextures,0));
    objects.emplace_back(new Object(sf::Vector2f(3920.0f,2960.0f), objTextures,0));

    ///columns
    //columns- in front of altar
    objects.emplace_back(new Object(sf::Vector2f(1530.0f,3050.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(1940.0f,2840.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2350.0f,2630.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(1960.0f,3260.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2370.0f,3050.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2780.0f,2840.0f), objTextures,2));
    //columns- left
    objects.emplace_back(new Object(sf::Vector2f(2470.0f,1900.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2170.0f,2060.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2980.0f,2160.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(2680.0f,2320.0f), objTextures,2));
    //columns- right
    objects.emplace_back(new Object(sf::Vector2f(4260.0f,2820.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(3960.0f,2980.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(3750.0f,2560.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(3450.0f,2720.0f), objTextures,2));
    //columns- behind altar
    objects.emplace_back(new Object(sf::Vector2f(4000.0f,1850.0f), objTextures,2));
    objects.emplace_back(new Object(sf::Vector2f(4440.0f,2080.0f), objTextures,2));

    ///benches
    //benches- in front of altar
    objects.emplace_back(new Object(sf::Vector2f(2930.0f,2630.0f), objTextures,5));
    objects.emplace_back(new Object(sf::Vector2f(3150.0f,2740.0f), objTextures,7));
    objects.emplace_back(new Object(sf::Vector2f(2790.0f,2710.0f), objTextures,4));
    objects.emplace_back(new Object(sf::Vector2f(3010.0f,2820.0f), objTextures,6));
    objects.emplace_back(new Object(sf::Vector2f(2650.0f,2790.0f), objTextures,6));
    objects.emplace_back(new Object(sf::Vector2f(2870.0f,2900.0f), objTextures,7));
    objects.emplace_back(new Object(sf::Vector2f(2570.0f,2600.0f), objTextures,5));
    objects.emplace_back(new Object(sf::Vector2f(3230.0f,2930.0f), objTextures,4));
    //benches-behind altar
    objects.emplace_back(new Object(sf::Vector2f(3530.0f,2330.0f), objTextures,4));
    objects.emplace_back(new Object(sf::Vector2f(3750.0f,2440.0f), objTextures,6));
    objects.emplace_back(new Object(sf::Vector2f(3690.0f,2250.0f), objTextures,5));
    objects.emplace_back(new Object(sf::Vector2f(3910.0f,2360.0f), objTextures,7));
    objects.emplace_back(new Object(sf::Vector2f(3850.0f,2170.0f), objTextures,6));
    objects.emplace_back(new Object(sf::Vector2f(4070.0f,2280.0f), objTextures,4));

    ///fire columns
    //fire colums- altar
    objects.emplace_back(new Object(sf::Vector2f(3350.0f,2650.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(3015.0f,2490.0f), objTextures,1));
    //fire colums- in front of altar
    objects.emplace_back(new Object(sf::Vector2f(1630.0f,3230.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(1940.0f,3380.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(2040.0f,3020.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(2350.0f,3170.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(2450.0f,2810.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(2760.0f,2960.0f), objTextures,1));
    //fire colums- behind altar
    objects.emplace_back(new Object(sf::Vector2f(3520.0f,2220.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(3920.0f,2420.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(4030.0f,2030.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(4440.0f,2230.0f), objTextures,1));
    //fire colums- right
    objects.emplace_back(new Object(sf::Vector2f(4260.0f,2990.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(4080.0f,3080.0f), objTextures,1));
    //fire colums- left
    objects.emplace_back(new Object(sf::Vector2f(2490.0f,2080.0f), objTextures,1));
    objects.emplace_back(new Object(sf::Vector2f(2310.0f,2180.0f), objTextures,1));

    ///candles
    //candles-altar
    objects.emplace_back(new Object(sf::Vector2f(3520.0f,2620.0f), objTextures,8));
    objects.emplace_back(new Object(sf::Vector2f(3260.0f,2460.0f), objTextures,8));
    //candles-in front of altar
    objects.emplace_back(new Object(sf::Vector2f(1510.0f,2970.0f), objTextures,9));
    objects.emplace_back(new Object(sf::Vector2f(1700.0f,2870.0f), objTextures,9));
    objects.emplace_back(new Object(sf::Vector2f(1890.0f,2770.0f), objTextures,9));
    //candles-behind altar
    objects.emplace_back(new Object(sf::Vector2f(4210.0f,2100.0f), objTextures,8));
    objects.emplace_back(new Object(sf::Vector2f(4400.0f,2180.0f), objTextures,8));

    //altar
    objects.emplace_back(new Object(sf::Vector2f(3277.0f,2248.0f), objTextures,3));

    //throne
    objects.emplace_back(new Object(sf::Vector2f(4270.0f,2040.0f), objTextures,10));

}

void GState::initMaps()
{
    mapLayout["LEVEL_1"]={
            183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 183, 183,
            183, 183, 183, 184, 184, 186, 185, 184, 184, 184, 183, 183, 183,
              7,   7,   7,   7,  99, 189, 188, 187,  97,   7,   7,   7,   7,
              7,   7,   7,   7, 143,  52,  52,  52, 113,   7,   7,   7,   7,
              4,   7,  18,  18,   7,   4,   7,   4,   4,   4,   7,   4,   7,
              7,   7,  17,  14,  49,   7, 182, 181, 180,   7,   7,   4,   7,
              4,   7,   8,  52,   9,   4, 179, 178, 177,   4,   7,   4,   7,
              7,   7,   7,   7,   7,   7, 176, 175, 174,   7,   7,   7,   7,
              7,   7,   4,   4,   7,   4,   7,   4,   7,   4,   4,   4,   4,
              7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
              7,   7,   4,   4,   7,   4,   7,   4,   7,   4,   4,   4,   4,
              7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,   7,
              7,   7,   4,   4,   7,   4,   7,   4,   7,   4,   4,   4,   4,
};
    mapLayout["LEVEL_1_OBJ"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 55, 54, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 35, 53, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
            35, 51, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
};
    mapLayout["LEVEL_1_WALL"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             7,  5,  4,  3, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             2, 35, 56, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             1, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             1, 52, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             1, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             0, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
};
    mapLayout["LEVEL_1_WALL2"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  7,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  2,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  1,
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,  0,
};
    mapLayout["LEVEL_1_WALL_CORNER"]={
            35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
             6, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35
};
    mapLayout["LEVEL_1_TREES"]={
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
            120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,  54,   9,
            120, 120, 120, 120, 120, 120, 120, 120, 120,  36,  55,  10, 120,
            120,  99, 120, 120, 120,  18, 120,  27,  37,  45, 120,  63, 120,
            100,   0, 108,  36,  19,   9,  28,  72,  46,  90,  64, 120,  81,
              1, 109,  37, 120,  10, 120,  73, 120,  91, 120, 120,  82, 120,
};
    mapLayout["LEVEL_1_ENTRY"]={
             20,  19,  18,  17,  16,  15,  55,  55,  12,  11,  10,   9,   8,
};
    mapLayout["LEVEL_1_ENTRY2"]={
             55,  55,  55,  55,  55,  55,  14,  13,  55,  55,  55,  55,  55,
};

    mapLayout["LEVEL_2_FLOOR"]={
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 54, 53, 52, 51, 50, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 49, 48, 47, 46, 45, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29,  3, 11, 11,  2, 29, 29, 29, 44, 43, 42, 41, 40, 29, 29, 29, 29, 25, 24, 24, 16, 29, 29, 29, 29,
            29, 29, 29, 29,  9,  8,  8,  7, 29, 29, 29, 39, 38, 37, 36, 35, 29, 29, 29, 29, 22, 15, 21, 20, 29, 29, 29, 29,
            29, 29, 29, 29,  6,  5,  5, 13, 29, 29, 29, 34, 33, 32, 31, 30, 29, 29, 29, 29, 14, 18, 18, 17, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 25, 16, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  3, 10, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 22, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  9,  7, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 22, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  9,  7, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 22, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  9,  7, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 22, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  9,  7, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 22, 20, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  9,  7, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 14, 13, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,  6,  0, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,

};
    mapLayout["LEVEL_2_FLOOR2"]={
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 20, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 11, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 17, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            22, 22, 22,  9, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,  9, 22, 22, 22,
            20, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 20, 22, 22,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 16, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 20, 22, 22, 22, 22, 22, 22, 20, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 16, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 20, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22, 22, 22, 22, 22, 20, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22, 22, 22, 22, 22, 22,  9, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22,  9, 22, 22, 22, 22, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 16, 22, 22, 22, 20, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29,  9, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 16, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,
            29, 29, 29, 29, 29, 29, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 29, 29, 29, 29, 29, 29,

};
    mapLayout["LEVEL_2_WALL"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 73, 29, 68, 69, 68, 69, 28, 69, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 31, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 70, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 71, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 30, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 31, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 30, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 31, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 70, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 71, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            73, 29, 28, 69, 68, 69, 68, 29, 28, 69, 74, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  0, 39, 29, 68, 69, 28, 29, 21,
            31, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31,
            70, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 70,
            71, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 71,
            70, 18, 18, 18, 18, 18, 18, 18, 18, 16, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 70,
            71, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 71,
            30, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30,
            71, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 28, 69, 68, 69, 28, 29, 74,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 58, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 59, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 53, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 54, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 55, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 50, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 51, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 52, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 46, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 47, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 48, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 49, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 31, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 30, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 20, 29, 28, 29, 28, 29, 28,  5,  4, 29, 28, 29, 28, 29, 28, 29, 74, 19, 19, 19, 19, 19, 19,

};
    mapLayout["LEVEL_2_WALL2"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 61, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 70, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 71, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 21,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 70,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 71,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 16, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 70,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 71,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 32, 69, 68, 69, 28, 29, 74,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 20, 29, 28, 29, 28, 29, 28,  5,  4, 29, 28, 29, 28, 29, 28, 29, 74, 19, 19, 19, 19, 19, 19,

};
    mapLayout["LEVEL_2_WALL3"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 61, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 70, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 71, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 30, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 31, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 70, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 71, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 20, 29, 28, 19, 19, 19, 19, 19, 19, 19, 19,

};
    mapLayout["LEVEL_2_WALL4"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 16, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            60, 29, 36, 69, 68, 69, 21, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
            19, 19, 19, 19, 19, 19, 56, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 57, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
};
    mapLayout["LEVEL_2_CORNER"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 60, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            60, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19,
};
    mapLayout["LEVEL_2_CORNER2"]={
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 27, 19, 19, 19, 19, 19, 19,
            };


    maps["LEVEL_1"]=new Tilemap();
    maps["LEVEL_1"]->load(mapTextures["LEVEL_1"],mapLayout["LEVEL_1"],13,13,sf::Vector2i(160,80), sf::Vector2i (9,7),1);

    maps["LEVEL_1_OBJ"]=new Tilemap();
    maps["LEVEL_1_OBJ"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_OBJ"],13,5,sf::Vector2i(160,320), sf::Vector2i (8,8),1);

    maps["LEVEL_1_WALL"]=new Tilemap();
    maps["LEVEL_1_WALL"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL"],13,7,sf::Vector2i(160,320), sf::Vector2i (8,8),1);
    maps["LEVEL_1_WALL2"]=new Tilemap();
    maps["LEVEL_1_WALL2"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL2"],13,7,sf::Vector2i(160,320), sf::Vector2i (8,8),1);

    maps["LEVEL_1_WALL_CORNER"]=new Tilemap();
    maps["LEVEL_1_WALL_CORNER"]->load(mapTextures["LEVEL_1_OBJ"],mapLayout["LEVEL_1_WALL_CORNER"],13,2,sf::Vector2i(160,320), sf::Vector2i (8,8),1);
    maps["LEVEL_1_TREES"]=new Tilemap();
    maps["LEVEL_1_TREES"]->load(mapTextures["LEVEL_1_TREES"],mapLayout["LEVEL_1_TREES"],13,11,sf::Vector2i(160,385), sf::Vector2i (8,8),1);
    maps["LEVEL_1_ENTRY"]=new Tilemap();
    maps["LEVEL_1_ENTRY"]->load(mapTextures["LEVEL_1_ENTRY"],mapLayout["LEVEL_1_ENTRY"],13,1,sf::Vector2i(160,640), sf::Vector2i (8,8),1);
    maps["LEVEL_1_ENTRY2"]=new Tilemap();
    maps["LEVEL_1_ENTRY2"]->load(mapTextures["LEVEL_1_ENTRY"],mapLayout["LEVEL_1_ENTRY2"],13,1,sf::Vector2i(160,640), sf::Vector2i (8,8),1);
    maps["LEVEL_2_FLOOR"]=new Tilemap();
    maps["LEVEL_2_FLOOR"]->load(mapTextures["LEVEL_2_FLOOR"],mapLayout["LEVEL_2_FLOOR"],28,35,sf::Vector2i(160,80), sf::Vector2i (10,10),2);
    maps["LEVEL_2_FLOOR2"]=new Tilemap();
    maps["LEVEL_2_FLOOR2"]->load(mapTextures["LEVEL_2_FLOOR2"],mapLayout["LEVEL_2_FLOOR2"],28,35,sf::Vector2i(160,80), sf::Vector2i (10,10),2);
    maps["LEVEL_2_WALL"]=new Tilemap();
    maps["LEVEL_2_WALL"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_WALL"],29,36,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
    maps["LEVEL_2_WALL2"]=new Tilemap();
    maps["LEVEL_2_WALL2"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_WALL2"],29,36,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
    maps["LEVEL_2_WALL3"]=new Tilemap();
    maps["LEVEL_2_WALL3"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_WALL3"],29,11,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
    maps["LEVEL_2_WALL4"]=new Tilemap();
    maps["LEVEL_2_WALL4"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_WALL4"],29,36,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
    maps["LEVEL_2_CORNER"]=new Tilemap();
    maps["LEVEL_2_CORNER"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_CORNER"],29,11,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
    maps["LEVEL_2_CORNER2"]=new Tilemap();
    maps["LEVEL_2_CORNER2"]->load(mapTextures["LEVEL_2_WALL"],mapLayout["LEVEL_2_CORNER2"],29,19,sf::Vector2i(160,320), sf::Vector2i (10,10),2);
}

GState::GState(sf::RenderWindow* window,std::stack<Resources*>* layers):Resources(window,layers)

{
    this->potionTimer=5;
    float aspectRatio=float(window->getSize().x)/float(window->getSize().y);
    this->view=new sf::View();
    this->view->setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);
    this->initTextures();
    this->initObjects();
    this->initMaps();

    music.setVolume(5.0f);
    music.setLoop(true);
    music.play();

    //lvl 1
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(876.0f-160.0f,890.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(460.0,100.0),sf::Vector2f(2130.0f,950.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(2060.0f-80.0f,1340.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1400.0,100.0),sf::Vector2f(1040.0f-80.0f,1280.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1235.0f-80.0f,805.0f-40.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1435.0f-80.0f,801.0f-40.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1130.0f-80.0f,810.0f-40.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,100.0),sf::Vector2f(1270.0f-80.0f,840.0f-40.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(150.0,100.0),sf::Vector2f(1500.0f-80.0f,800.0f-40.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(900.0,100.0),sf::Vector2f(1600.0f-80.0f,770.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(100.0,100.0),sf::Vector2f(1450.0f-80.0f,810.0f-40.0f),0.0f));

    //lvl 2
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(750.0,100.0),sf::Vector2f(1180.0f,3387.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(750.0,100.0),sf::Vector2f(1980.0f,3790.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(2270.0,100.0),sf::Vector2f(2630.0f,3742.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(540.0,100.0),sf::Vector2f(3840.0f,3364.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(800.0,100.0),sf::Vector2f(4465.0f,3310.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1000.0,10.0),sf::Vector2f(4350.0f,2907.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(800.0,10.0),sf::Vector2f(4270.0f,2500.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(220.0,100.0),sf::Vector2f(4570.0f,2340.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(250.0,60.0),sf::Vector2f(4580.0f,2380.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1000.0,40.0),sf::Vector2f(4370.0f,2100.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(250.0,60.0),sf::Vector2f(4080.0f,2010.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(100.0,60.0),sf::Vector2f(4480.0f,2160.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(904.0,10.0),sf::Vector2f(3680.0f,2170.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(50.0,60.0),sf::Vector2f(3460.0f,2250.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(915.0,10.0),sf::Vector2f(2870.0f,2160.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,60.0),sf::Vector2f(2450.0f,1958.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(904.0,10.0),sf::Vector2f(2220.0f,2100.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(615.0,20.0),sf::Vector2f(2040.0f,2410.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(1515.0,10.0),sf::Vector2f(1650.0f,2875.0f),334.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(50.0,60.0),sf::Vector2f(1470.0f,2945.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(50.0,60.0),sf::Vector2f(1650.0f,2845.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(50.0,60.0),sf::Vector2f(1860.0f,2750.0f),0.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,20.0),sf::Vector2f(3440.0f,2570.0f),207.0f));
    walls.emplace_back(new Wall(&textureWall,sf::Vector2f(40.0,40.0),sf::Vector2f(3310.0f,2530.0f),0.0f));

    //teleport
    teleport.emplace_back(new Wall(&textureWall,sf::Vector2f(50.0,50.0),sf::Vector2f(1890.0f,810.0f),0.0f));
    teleport.emplace_back(new Wall(&textureWall,sf::Vector2f(200.0,50.0),sf::Vector2f(1570.0f,3580.0f),207.0f));
}

GState::~GState()
{
    delete this->player;
    delete this->view;
    for(auto &it:maps){
        delete it.second;
    }
    for(auto &it:walls){
        delete it;
    }
    delete this->playerGUI;
    for(auto &it:enemies){
        delete it;
    }
    for(auto &it:enemyGUI){
        delete it;
    }
    for(auto &it:objects){
        delete it;
    }
}

void GState::updateCombat(const float& deltaTime)
{
        for(auto &it:enemies){
            if(it->hitbox->getGlobalB().contains(mousePosView)){
                enemy=it;
            }
        }
        if(player->getAttacking()==true){
            if(enemy){
                if(enemy->getDistance(*this->player)<this->player->range && enemy->hitbox->getGlobalB().contains(mousePosView)){
                    if(player->getAtck()){
                    enemy->loseHP(player->attackDmg,deltaTime);
                    std::cout<<enemy->hp<<std::endl;
                    }
                }
            }
        }
        for(auto &it:enemies){
            if(it->getDistance(*this->player)<300){
                if(it->hitboxAttack->getGlobalB().intersects(player->hitboxAttack->getGlobalBounds())){
                    it->move(sf::Vector2f(0.0f,0.0f), deltaTime);

                    for(unsigned int i=0;i<enemies.size();i++){
                        if(it==enemies[i]){
                        }else{
                        if(collision::areColliding(it->hitboxAttack,enemies[i]->hitboxAttack,enemies[i],deltaTime,it->hitboxAttack->getRotation(),0)){
                            if(!enemies[i]->getAttacking()){
                                enemies[i]->move(sf::Vector2f(0.0f,0.0f),deltaTime);
                            }
                        }
                    }
                    }


                    if(it->getAtck()){
                        player->loseHP(it->attackDmg,deltaTime);
                    }
                    if(it->hp>0){
                        it->updateAttack();
                    }

                }else{
                    if(player->hitboxAttack->getPosition().y > it->hitboxAttack->getPosition().y+it->hitboxAttack->getGlobalB().height){
                        it->move(sf::Vector2f(0.0f,1.0f), deltaTime);
                    }
                    if (player->hitboxAttack->getPosition().y+player->hitboxAttack->getGlobalB().height < it->hitboxAttack->getPosition().y){
                        it->move(sf::Vector2f(0.0f,-1.0f), deltaTime);
                    }
                    if(player->hitboxAttack->getPosition().x > it->hitboxAttack->getPosition().x+it->hitboxAttack->getGlobalB().width){
                        it->move(sf::Vector2f(1.0f,0.0f), deltaTime);
                    }
                    if(player->hitboxAttack->getPosition().x+player->hitboxAttack->getGlobalB().width < it->hitboxAttack->getPosition().x){
                        it->move(sf::Vector2f(-1.0f,0.0f), deltaTime);
                    }
                    if(player->hitboxAttack->getPosition().y > it->hitboxAttack->getPosition().y+it->hitboxAttack->getGlobalB().height&&player->hitboxAttack->getPosition().x > it->hitboxAttack->getPosition().x+it->hitboxAttack->getGlobalB().width){
                        it->move(sf::Vector2f(1.0f,1.0f), deltaTime);
                    }
                    if(player->hitboxAttack->getPosition().y > it->hitboxAttack->getPosition().y+it->hitboxAttack->getGlobalB().height&&player->hitboxAttack->getPosition().x+player->hitboxAttack->getGlobalB().width < it->hitboxAttack->getPosition().x){
                        it->move(sf::Vector2f(-1.0f,1.0f), deltaTime);
                    }
                    if (player->hitboxAttack->getPosition().y+player->hitboxAttack->getGlobalB().height < it->hitboxAttack->getPosition().y&&player->hitboxAttack->getPosition().x > it->hitboxAttack->getPosition().x+it->hitboxAttack->getGlobalB().width){
                        it->move(sf::Vector2f(1.0f,-1.0f), deltaTime);
                    }
                    if (player->hitboxAttack->getPosition().y+player->hitboxAttack->getGlobalB().height < it->hitboxAttack->getPosition().y&&player->hitboxAttack->getPosition().x+player->hitboxAttack->getGlobalB().width < it->hitboxAttack->getPosition().x){
                        it->move(sf::Vector2f(-1.0f,-1.0f), deltaTime);
                    }
                }
            }else{
                it->move(sf::Vector2f(0.0f,0.0f),deltaTime);
            }
        }
}

void GState::updateView()
{
    this->view->setCenter(this->player->getPosition().x+39,this->player->getPosition().y+46);
}

void GState::updateInput(const float &deltaTime)
{
    this->player->update(deltaTime);

    this->updateView();
    this->player->move(sf::Vector2f(0.0f,0.0f),deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->player->move(sf::Vector2f(-1.0f,0.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->player->move(sf::Vector2f(1.0f,0.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->player->move(sf::Vector2f(0.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player->move(sf::Vector2f(0.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player->move(sf::Vector2f(-1.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player->move(sf::Vector2f(1.0f,1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->player->move(sf::Vector2f(-1.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->player->move(sf::Vector2f(1.0f,-1.0f),deltaTime);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        if(potionTimer<1&&player->hp>0){
            player->gainHP(player->hpMax);
            potionTimer=30;
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    if(mousePosView.y > this->player->hitboxAttack->getPosition().y+this->player->hitboxAttack->getGlobalB().height&&mousePosView.x>this->player->hitboxAttack->getPosition().x&&mousePosView.x<this->player->hitboxAttack->getPosition().x+this->player->hitboxAttack->getGlobalB().width){
        this->player->setRow(0);
        }
    if (mousePosView.y < this->player->hitboxAttack->getPosition().y&&mousePosView.x>this->player->hitboxAttack->getPosition().x&&mousePosView.x<this->player->hitboxAttack->getPosition().x+this->player->hitboxAttack->getGlobalB().width){
        this->player->setRow(8);
        }
    if (mousePosView.x < this->player->hitboxAttack->getPosition().x&&mousePosView.y>this->player->hitboxAttack->getPosition().y&&mousePosView.y<this->player->hitboxAttack->getPosition().y+this->player->hitboxAttack->getGlobalB().height){
        this->player->setRow(4);
        }
    if (mousePosView.x > this->player->hitboxAttack->getPosition().x+this->player->hitboxAttack->getGlobalB().width&&mousePosView.y>this->player->hitboxAttack->getPosition().y&&mousePosView.y<this->player->hitboxAttack->getPosition().y+this->player->hitboxAttack->getGlobalB().height){
        this->player->setRow(12);
    }
    if (mousePosView.y > this->player->hitboxAttack->getPosition().y+this->player->hitboxAttack->getGlobalB().height&&mousePosView.x>this->player->hitboxAttack->getPosition().x+this->player->hitboxAttack->getGlobalB().width){
        this->player->setRow(14);
    }
    if (mousePosView.y > this->player->hitboxAttack->getPosition().y+this->player->hitboxAttack->getGlobalB().height&&mousePosView.x<this->player->hitboxAttack->getPosition().x){
        this->player->setRow(2);
    }
    if (mousePosView.y < this->player->hitboxAttack->getPosition().y&&mousePosView.x<this->player->hitboxAttack->getPosition().x){
        this->player->setRow(6);
    }
    if (mousePosView.y < this->player->hitboxAttack->getPosition().y&&mousePosView.x>this->player->hitboxAttack->getPosition().x+this->player->hitboxAttack->getGlobalB().width){
        this->player->setRow(10);
    }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endLayer();
    }
}

void GState::update(const float &deltaTime)
{
    if(oneSecond>1){
        oneSecond=0;
        if(player->hp>0){
            player->gainHP(1);
        }
    }
    for(unsigned int i=0;i<enemies.size();i++){
        enemyGUI[i]->updateEnemy();
    }
    oneSecond+=deltaTime;
    if(potionTimer>0)
        potionTimer-=deltaTime;
    this->updateMousePos();
    this->updateInput(deltaTime);
    this->playerGUI->update(potionTimer);
    this->player->hitbox->update();
    this->player->hitboxAttack->update();

    for(unsigned int i=0;i<enemyGUI.size();i++){

        enemies[i]->hitbox->update();
        enemies[i]->hitboxAttack->update();
        if(enemies[i]->getDie()){
            delete enemyGUI[i];
            enemyGUI.erase(std::remove(enemyGUI.begin(), enemyGUI.end(), enemyGUI[i]), enemyGUI.end());

            delete enemies[i];
            enemies.erase(std::remove(enemies.begin(), enemies.end(), enemies[i]), enemies.end());
            enemy=nullptr;
        }
    }

    for(auto &it:walls){
        collision::areColliding(it,player->hitbox,player,deltaTime,it->getRotation(),2);
        for(auto &i:enemies){
            collision::areColliding(it,i->hitbox,i,deltaTime,it->getRotation(),2);
        }
    }
    for(auto &it:enemies){
        if(!it->getDie())
        {
            collision::areColliding(it->hitboxAttack,player->hitboxAttack,player,deltaTime,it->hitboxAttack->getRotation(),0);
            it->update(deltaTime);
        }

        if(this->player->hitboxAttack->getPosition().y<it->hitboxAttack->getPosition().y){
            it->setRenderNum(1);
        }else{
            it->setRenderNum(0);
        }
    }
    if(teleport[0]->getGlobalBounds().intersects(player->hitbox->getGlobalBounds())){
        player->setPosition(sf::Vector2f(1570.0f,3470.0f));
    }
    if(collision::areColliding(teleport[1],player->hitbox,player,deltaTime,teleport[1]->getRotation(),2)){
        player->setPosition(sf::Vector2f(1800.0f,870.0f));
    }

    for(auto &it:objects){
        if(it->hitboxAttack)
            if(it->getType()==0||it->getType()==1||it->getType()==2||it->getType()==3||it->getType()==8||it->getType()==9||it->getType()==10)
                collision::areColliding(it->hitboxAttack,player->hitboxAttack,player,deltaTime,it->hitboxAttack->getRotation(),0);

        it->update(deltaTime);

        if(it->hitboxAttack){
            it->hitboxAttack->update();
            if(this->player->hitboxAttack->getPosition().y<it->hitboxAttack->getPosition().y){
                it->setRenderNum(1);
            }else{
                it->setRenderNum(0);
            }
        }
    }

    this->updateCombat(deltaTime);

    for(unsigned int i=1;i<enemies.size();i++){

        for(auto &it:objects){
            if(it->getType()==0||it->getType()==1||it->getType()==2||it->getType()==3||it->getType()==8||it->getType()==9||it->getType()==10)
            collision::areColliding(it->hitboxAttack,enemies[i]->hitboxAttack,enemies[i],deltaTime,it->hitboxAttack->getRotation(),0);
        }
    }
}

void GState::render(sf::RenderWindow* window)
{
    this->window->setView(*view);
    window->draw(*maps["LEVEL_1"]);
    window->draw(*maps["LEVEL_2_FLOOR2"]);
    window->draw(*maps["LEVEL_2_FLOOR"]);
    window->draw(*maps["LEVEL_1_ENTRY"]);
    window->draw(*maps["LEVEL_1_WALL"]);
    window->draw(*maps["LEVEL_2_CORNER"]);
    window->draw(*maps["LEVEL_2_WALL"]);
    window->draw(*maps["LEVEL_1_WALL_CORNER"]);
    window->draw(*maps["LEVEL_1_OBJ"]);

    if(this->player->hitbox->getGlobalBounds().top>878){
        for(auto &it:objects){
            if(it->getRenderNum()==0){
                it->render(*window);
            }
        }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            window->draw(*maps["LEVEL_1_ENTRY2"]);
            this->player->render(*window);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }
        }else if(this->player->hitbox->getGlobalBounds().top<878){
        for(auto &it:objects){
            if(it->getRenderNum()==0){
                it->render(*window);
            }
        }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            this->player->render(*window);
            window->draw(*maps["LEVEL_1_ENTRY2"]);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }

        }
    if(this->player->hitbox->getGlobalB().left>3200)
    {
        if(this->player->hitboxAttack->getGlobalB().top>2730){
            for(auto &it:objects){
                if(it->getRenderNum()==0){
                    it->render(*window);
                }
            }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            window->draw(*maps["LEVEL_2_WALL3"]);
            this->player->render(*window);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }
        }else if(this->player->hitboxAttack->getGlobalB().top<2730){
            for(auto &it:objects){
                if(it->getRenderNum()==0){
                    it->render(*window);
                }
            }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            this->player->render(*window);
            window->draw(*maps["LEVEL_2_WALL3"]);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }
        }
    }else if(this->player->hitbox->getGlobalB().left<3200&&this->player->hitbox->getGlobalB().top>1600)
    {
        if(this->player->hitboxAttack->getGlobalB().top>2569){
            for(auto &it:objects){
                if(it->getRenderNum()==0){
                    it->render(*window);
                }
            }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            window->draw(*maps["LEVEL_2_WALL4"]);
            this->player->render(*window);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }
        }else if(this->player->hitboxAttack->getGlobalB().top<2569){
            for(auto &it:objects){
                if(it->getRenderNum()==0){
                    it->render(*window);
                }
            }
            for(auto &it:enemies){
                if(it->getRenderNum()==0&&it->getDie()==false){
                    it->render(*window);
                }
            }
            this->player->render(*window);
            window->draw(*maps["LEVEL_2_WALL4"]);
            for(auto &it:enemies){
                if(it->getRenderNum()==1&&it->getDie()==false){
                    it->render(*window);
                }
            }
            for(auto &it:objects){
                if(it->getRenderNum()==1){
                    it->render(*window);
                }
            }
        }
    }

    window->draw(*maps["LEVEL_1_TREES"]);
    window->draw(*maps["LEVEL_1_WALL2"]);
    window->draw(*maps["LEVEL_2_CORNER2"]);
    window->draw(*maps["LEVEL_2_WALL2"]);
    for(unsigned int i=0;i<enemies.size();i++){
        if(enemies[i]->hitbox->getGlobalB().contains(mousePosView)){
            enemyGUI[i]->renderEnemy(window);
        }
    }

    playerGUI->render(window,enemies.size());

    /*for(auto &it:walls){
        window->draw(*it);
    }
    for(auto &it:teleport){
        window->draw(*it);
    }*/
}
