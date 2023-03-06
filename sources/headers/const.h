//
// Created by chest on 2023-02-27.
//

#ifndef MINESWEEPER_CONST_H
#define MINESWEEPER_CONST_H

enum class EasyLevel {
    ROWS = 9,
    COLS = 9,
    MINE_INIT_COUNT = 10
};

enum class NormalLevel {
    ROWS = 12,
    COLS = 16,
    MINE_INIT_COUNT = 30
};

enum class HardLevel {
    ROWS = 16,
    COLS = 30,
    MINE_INIT_COUNT = 99
};


static constexpr int kMinCustomRows = 9;
static constexpr int kMaxCustomRows = 16;

static constexpr int kMinCustomCols = 9;
static constexpr int kMaxCustomCols = 30;

static constexpr int kMinCustomMineCount = 10;
static constexpr int kMaxCustomMineCount = 400;

// rows*cols总数中雷所占的最大比例
static constexpr double kMaxMineProportion = 0.8;

// Block的边长
static constexpr int kBlockLength = 30;

// Block之间的间距
static constexpr int kBlockSpacing = 5;

// Layout距离顶部窗口边框的距离
static constexpr int kTopMargin = 9;
// Layout距离底部窗口边框的距离
static constexpr int kBottomMargin = 3;

// TopBoard、BottomBoard的宽度等于BlockBoard，只需指定高度
static constexpr int kTopBoardHeight = 60;
static constexpr int kBottomBoardHeight = 90;

// 垂直方向上各Board之间的间距，以及和上下窗口边框的距离
static constexpr int kBoardSpacing = 12;

// 水平方向上距窗口边框的距离
static constexpr int kMarginX = 15;

// emoji图片的最大编号，参考images文件夹下的资源
static constexpr int kMaxEmojiNumber = 13;

// GameOverDialog中显示的emoji的边长
static constexpr int kOverEmojiLength = 60;

enum ColorConst {
    LightGray = 0xFFF0F0F0,
    White = 0xFFFFFFFF,
    LightBlack = 0xFF363636,
    Blue = 0x3c8cc4
};

enum Color {
    BgColor = ColorConst::LightGray,
    BlockBoardBgColor = ColorConst::White,
    TopBoardBgColor = ColorConst::White,
    LightBlackTextColor = ColorConst::LightBlack,
    NumberBlockColor = ColorConst::Blue
};

#endif //MINESWEEPER_CONST_H
