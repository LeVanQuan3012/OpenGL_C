for (int thicknessCount = 0; thicknessCount < thickness / 2; thicknessCount++) {
        for (i = x1; i <= x2; i++) {
            // V? c�c �i?m ngang t?o n�t �?t
            // �i?m (i, y1) �?n (i, y2)
            if (net < 5) {
                glVertex2i(i, y1);
            }
            net = (net + 1) % 10;
        }

        for (i = y1; i <= y2; i++) {
            // V? c�c �i?m d?c t?o n�t �?t
            // �i?m (x1, i) �?n (x2, i)
            if (net < 5) {
                glVertex2i(x1, i);
            }
            net = (net + 1) % 10;
        }

        x1 += stepX;
        x2 += stepX;
        p += twoDy;
        if (p >= 0) {
            y1 += stepY;
            y2 += stepY;
            p += twoDyMinusDx;
        }
    }
