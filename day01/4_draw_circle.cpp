class DrawCircle {
public:
    void drawCircle(bool isDraw, bool isOutline, int x, int y, double radius) {
        if (x == 0 && y == 0) {
            firstDraw(radius);
        }
        else {
            if (isDraw) {
                if (isOutline) {
                    circle_draw2(x, y, radius);
                }
                else {
                    circle_draw(x, y, radius);
                }
            }
            else {
                circleDelete(x, y, radius);
            }
        }
    }

private:
    void circle_draw(int x, int y, double radius) {
        //원을 화면에 그린다.
    }

    void circleDelete(int x, int y, double radius) {
        //원을 화면에 지운다.
    }

    void circle_draw2(int x, int y, double radius) {
        //테두리가 있는 원을 화면에 그린다.
    }

    void firstDraw(double radius) {
        //0, 0 에 그림을 그리지 못하도록 예외처리
        //에러 출력 하지 않고, 아무것도 하지 않는다.
    }
};
