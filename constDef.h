#ifndef CONSTDEF_H
#define CONSTDEF_H

namespace constDef {
constexpr int CircleRadius = 50;                        // 圆半径
constexpr int RowNum = 5;                               // 行数
constexpr int ColNum = 15;                              // 列数
constexpr int RectWidth = CircleRadius * 2 * ColNum;    // 矩形框宽度
constexpr int RectHeight = CircleRadius * 2 * RowNum;   // 矩形框高度
constexpr int Space = 10;                               // 空间尺寸
}

#endif // CONSTDEF_H
