#include <iostream>
#include <cstdlib>
#include <unistd.h>

#define DELAY 1

int delay = DELAY;
int location = 1;
int haveFlowers = 0;
int haveSword = 0;
int ateSpinach = 0;
int dead = 0;
int killedSlug = 0;
int killedDragon = 0;
int savedPrincess = 0;
int coward = 0;
int action;

void doError() {
    std::cout << "Что!?\n";
    sleep(delay);
}

int getAction() {
    int action;
    std::cin >> action;
    return action;
}

void doMove() {
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << "\n\n\n";
}

void doLocation1() {
    std::cout << "Вы видите вход в пещеру на севере.\n";
    std::cout << "Вы слышите, как принцесса кричит: \"Помогите!\"\n";
    std::cout << "Вы также слышите громкий рев.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Войти в пещеру\n";
    std::cout << "2) Убежать\n";
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 2;
            break;
        case 2:
            coward = 1;
            break;
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation2() {
    std::cout << "Вы внутри пещеры. Запах серы подавляющий.\n";
    std::cout << "Вы видите коридор, ведущий на запад, коридор, ведущий на восток,\n";
    std::cout << "и коридор, ведущий на юг.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на восток\n";
    std::cout << "2) Идти на запад\n";
    std::cout << "3) Идти на юг\n";
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 4;
            break;
        case 2:
            location = 3;
            break;
        case 3:
            location = 1;
            break;
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation3() {
    std::cout << "Здесь действительно темно.\n";
    sleep(2 * delay);
    std::cout << "Вы ничего не видите.\n";
    sleep(2 * delay);
    std::cout << "Вы блуждаете по комнате и наконец находите выход.\n";
    location = 2;
    doMove();
}

void doLocation4() {
    std::cout << "Вы находитесь в комнате, которая пуста, кроме паутины повсюду.\n";
    std::cout << "Есть коридоры, ведущие на запад, на север и на восток.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на восток\n";
    std::cout << "2) Идти на север\n";
    std::cout << "3) Идти на запад\n";
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 5;
            break;
        case 2:
            location = 8;
            break;
        case 3:
            location = 2;
            break;
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation5() {
    if (!ateSpinach) {
        std::cout << "Вы находитесь в комнате.\n";
        std::cout << "Вы видите банку шпината.\n";
    } else {
        std::cout << "Вы находитесь в комнате с пустой банкой шпината.\n";
    }
    std::cout << "Есть коридор на запад.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на запад\n";
    if (!ateSpinach) {
        std::cout << "2) Съесть шпинат\n";
    }
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 4;
            break;
        case 2:
            if (!ateSpinach) {
                std::cout << "Фу!\n";
                std::cout << "Вы чувствуете себя гораздо сильнее\n";
                ateSpinach = 1;
                break;
            }
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation6() {
    if (!haveSword) {
        std::cout << "Вы находитесь в комнате.\n";
        std::cout << "Вы видите меч, лежащий на большом камне.\n";
    } else {
        std::cout << "Вы находитесь в комнате с большим камнем.\n";
    }
    std::cout << "Есть коридор на восток.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на восток\n";
    if (!haveSword) {
        std::cout << "2) Взять меч\n";
    }
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 7;
            break;
        case 2:
            if (!haveSword) {
                std::cout << "Вы берете меч.\n";
                haveSword = 1;
                break;
            }
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation7() {
    if (!killedSlug) {
        std::cout << "Вы находитесь в комнате.\n";
        std::cout << "На земле вы видите отвратительного слизня.\n";
        std::cout << "Что вы делаете?\n";
        std::cout << "1) Убежать как маленькая девочка\n";
        std::cout << "2) Наступить на слизня\n";
        std::cout << "? ";
        action = getAction();
        switch (action) {
            case 1:
                std::cout << "Вы закричали и убежали.\n";
                std::cout << "Вы слышите, как принцесса кричит,\n";
                std::cout << "\"Мне что, самой себя спасать!?\"\n";
                location = 8;
                break;
            case 2:
                std::cout << "Вы получили слизь на своих ботинках,\n";
                std::cout << "когда раздавили слизня.\n";
                killedSlug = 1;
                break;
            default:
                doError();
                break;
        }
    } else {
        std::cout << "Вы находитесь в комнате с внутренностями слизня на полу.\n";
        std::cout << "Есть коридоры на запад и восток.\n";
        std::cout << "Что вы делаете?\n";
        std::cout << "1) Идти на запад\n";
        std::cout << "2) Идти на восток\n";
        std::cout << "? ";
        action = getAction();
        switch (action) {
            case 1:
                location = 6;
                break;
            case 2:
                location = 8;
                break;
            default:
                doError();
                break;
        }
    }
    doMove();
}

void doLocation8() {
    std::cout << "Вы находитесь в пустой комнате. Здесь очень тепло.\n";
    std::cout << "Есть коридоры на запад, на север, на восток и на юг.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на запад\n";
    std::cout << "2) Идти на север\n";
    std::cout << "3) Идти на восток\n";
    std::cout << "4) Идти на юг\n";
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 7;
            break;
        case 2:
            location = 10;
            break;
        case 3:
            location = 9;
            break;
        case 4:
            location = 4;
            break;
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation9() {
    if (!haveFlowers) {
        std::cout << "Вы находитесь в комнате.\n";
        std::cout << "На земле вы видите цветы.\n";
    } else {
        std::cout << "Вы находитесь в комнате. Вы видите участок земли,\n";
        std::cout << "где когда-то росли цветы.\n";
    }
    std::cout << "Есть коридор на запад.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Идти на запад\n";
    if (!haveFlowers) {
        std::cout << "2) Сорвать цветы\n";
    }
    std::cout << "? ";
    action = getAction();
    switch (action) {
        case 1:
            location = 8;
            break;
        case 2:
            if (!haveFlowers) {
                std::cout << "Вы сорвали цветы.\n";
                std::cout << "Они пахнут прекрасно.\n";
                haveFlowers = 1;
                break;
            }
        default:
            doError();
            break;
    }
    doMove();
}

void doLocation10() {
    if (!killedDragon) {
        std::cout << "Вы находитесь в комнате.\n";
        sleep(2 * delay);
        std::cout << "Вы видите кровожадного дракона!!!\n";
        sleep(2 * delay);
        std::cout << "Вы немного намочили штаны.\n";
        sleep(2 * delay);
        std::cout << "Что вы делаете?\n";
        std::cout << "1) Убежать\n";
        std::cout << "2) Сразиться с драконом\n";
        std::cout << "? ";
        action = getAction();
        switch (action) {
            case 1:
                std::cout << "Вы убегаете, крича.\n";
                std::cout << "Вы слышите, как принцесса говорит,\n";
                std::cout << "\"Какой трус!\"\n";
                location = 8;
                break;
            case 2:
                if (!haveSword) {
                    std::cout << "Вы бросаетесь на дракона.\n";
                    sleep(2 * delay);
                    std::cout << "Он смеется, пока вы отчаянно царапаете его\n";
                    std::cout << "голыми руками.\n";
                    sleep(2 * delay);
                    std::cout << "Затем он поглощает вас одним укусом.\n";
                    sleep(2 * delay);
                    std::cout << "Вы мертвы.\n";
                    dead = 1;
                } else if (!ateSpinach) {
                    std::cout << "Вы бросаетесь на дракона, размахивая мечом.\n";
                    sleep(2 * delay);
                    std::cout << "У вас не хватает сил, чтобы пробить его чешую.\n";
                    sleep(2 * delay);
                    std::cout << "Дракон изрыгает огонь и сжигает вас до хрустящей корочки.\n";
                    sleep(2 * delay);
                    std::cout << "Вы мертвы.\n";
                    dead = 1;
                } else {
                    std::cout << "Вы бросаетесь на дракона, размахивая мечом.\n";
                    sleep(2 * delay);
                    std::cout << "Вы вонзаете меч глубоко в\n";
                    std::cout << "черное сердце дракона.\n";
                    sleep(2 * delay);
                    std::cout << "Дракон делает последний вздох...\n";
                    sleep(2 * delay);
                    std::cout << "и падает мертвым.\n";
                    sleep(2 * delay);
                    killedDragon = 1;
                }
                break;
            default:
                doError();
                break;
        }
    } else {
        std::cout << "Вы находитесь в комнате с тушей мертвого дракона.\n";
        std::cout << "Есть коридор на юг и на север.\n";
        std::cout << "Что вы делаете?\n";
        std::cout << "1) Идти на север\n";
        std::cout << "2) Идти на юг\n";
        std::cout << "? ";
        action = getAction();
        switch (action) {
            case 1:
                location = 11;
                break;
            case 2:
                location = 8;
                break;
            default:
                doError();
                break;
        }
    }
    doMove();
}

void doLocation11() {
    if (!haveFlowers) {
        std::cout << "Вы входите в комнату.\n";
        sleep(2 * delay);
        std::cout << "Вы видите самую красивую женщину, которую когда-либо видели!\n";
        sleep(2 * delay);
        std::cout << "Она выглядит расстроенной.\n";
        sleep(2 * delay);
        std::cout << "Что!? Нет цветов!?\n";
        sleep(2 * delay);
        std::cout << "Она сердито выталкивает вас из комнаты.\n";
        location = 10;
    } else {
        std::cout << "Вы входите в комнату.\n";
        sleep(2 * delay);
        std::cout << "Вы видите самую красивую женщину, которую когда-либо видели!\n";
        sleep(2 * delay);
        std::cout << "Она бежит к вам с открытыми руками.\n";
        sleep(2 * delay);
        std::cout << "Она говорит: \"Мой герой!!!\"\n";
        sleep(2 * delay);
        std::cout << "\"Какие прекрасные цветы!\"\n";
        sleep(2 * delay);
        std::cout << "\"Вытащи меня из этого проклятого ада!\"\n";
        savedPrincess = 1;
    }
    doMove();
}

int main() {
    std::cout << "Король зовет всех рыцарей страны.\n";
    sleep(2 * delay);
    std::cout << "Его дочь, принцесса, была похищена злым драконом.\n";
    sleep(2 * delay);
    std::cout << "Король обещает руку принцессы тому, кто сможет ее спасти.\n";
    sleep(2 * delay);
    std::cout << "Вы смело принимаете его предложение и отправляетесь в темный лес.\n";
    doMove();

    while (!dead && !savedPrincess && !coward) {
        switch (location) {
            case 1:
                doLocation1();
                break;
            case 2:
                doLocation2();
                break;
            case 3:
                doLocation3();
                break;
            case 4:
                doLocation4();
                break;
            case 5:
                doLocation5();
                break;
            case 6:
                doLocation6();
                break;
            case 7:
                doLocation7();
                break;
            case 8:
                doLocation8();
                break;
            case 9:
                doLocation9();
                break;
            case 10:
                doLocation10();
                break;
            case 11:
                doLocation11();
                break;
        }
    }

    if (savedPrincess) {
        std::cout << "Вы спасли принцессу.\n";
        sleep(2 * delay);
        std::cout << "Вы женитесь на ней и живете долго и счастливо.\n";
        sleep(2 * delay);
    } else if (dead) {
        std::cout << "Вы погибли.\n";
        sleep(2 * delay);
        std::cout << "За вашу храбрость король возводит статую.\n";
        sleep(2 * delay);
        std::cout << "На вас будут срать птицы всю вечность.\n";
        sleep(2 * delay);
    } else if (coward) {
        std::cout << "Вы убегаете как трус.\n";
        sleep(2 * delay);
        std::cout << "Когда вы убегаете, вы слышите звук дракона,\n";
        std::cout << "жующего принцессу.\n";
        sleep(2 * delay);
        std::cout << "За ваше трусость король арестовывает вас\n";
        sleep(2 * delay);
        std::cout << "и вы проводите остаток своей жалкой жизни в подземелье.\n";
    }
}

