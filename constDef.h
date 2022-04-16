/**
 * @class
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   常量统一定义
 * @note
*/

#ifndef CONSTDEF_H
#define CONSTDEF_H

// 通用常量
namespace constDef {
// 圆周率
constexpr double PI = 3.1415926;
// 空间尺寸
constexpr int Space = 10;
// 图片统一尺寸(与显示大小无关)
constexpr int PicSize = 500;
}

// 头像相关
namespace constDef {
// 圆半径
constexpr int CircleRadius = 15;
// 圆直径
constexpr int CircleDiameter = CircleRadius * 2;
// 行数
constexpr int RowNum = 10;
// 列数
constexpr int ColNum = 20;
// 广发-临时
const QString guangfa(":imageRes/res/guangfa.jpg");
// 拓海-临时
const QString tuohai(":imageRes/res/tuohai.jpg");
}

// 大矩形框相关
namespace constDef {
// 矩形框宽度
constexpr int RectWidth = CircleDiameter * ColNum;
// 矩形框高度
constexpr int RectHeight = CircleDiameter * RowNum;
}

// 成语相关
namespace constDef {
// 成语矩形框X坐标
constexpr int IdiomAreaX = 70;
// 成语矩形框Y坐标
constexpr int IdiomAreaY = 70;
// 成语文字X坐标
constexpr int IdiomTextX = IdiomAreaX + 30;
// 成语文字Y坐标
constexpr int IdiomTextY = IdiomAreaY + 60;
// 字体尺寸
constexpr int TextSize = 20;
// 成语矩形框宽度
constexpr int IdiomAreaWidth = 180;
// 成语矩形框高度
constexpr int IdiomAreaHeight = 100;
}

// 炸弹相关
namespace constDef {
constexpr int FocusX = 450 + Space;
constexpr int FocusY = 200 + Space;
}

// 状态框相关
namespace constDef {
constexpr int StatusWidth = 40;
constexpr int StatusHeight = 150;
constexpr int StatusWidthTotal = StatusWidth * 10;
constexpr int StatusHeightTotal = StatusHeight;
}

#endif // CONSTDEF_H
