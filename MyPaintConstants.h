#pragma once

// перечисление возможных типов рисуемого элемента
enum ElementType { LINE, RECTANGLE, ELLIPSE, CURVE };

// возможные цвета
const COLORREF BLACK = RGB(0, 0, 0);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF WHITE = RGB(255, 255, 255);