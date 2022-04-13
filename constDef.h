#ifndef CONSTDEF_H
#define CONSTDEF_H

namespace constDef {
constexpr int CircleRadius = 15;                        // 圆半径
constexpr int CircleDiameter = CircleRadius * 2;        // 圆直径
constexpr int RowNum = 10;                              // 行数
constexpr int ColNum = 20;                              // 列数
constexpr int RectWidth = CircleRadius * 2 * ColNum;    // 矩形框宽度
constexpr int RectHeight = CircleRadius * 2 * RowNum;   // 矩形框高度
constexpr int Space = 10;                               // 空间尺寸
constexpr int PicSize = 300;                            // 图片统一尺寸(与显示大小无关)
constexpr double PI = 3.1415926;                        // 圆周率
//constexpr int
}

#endif // CONSTDEF_H
