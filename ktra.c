for (int thicknessCount = 0; thicknessCount < thickness / 2; thicknessCount++) {
        for (i = x1; i <= x2; i++) {
            // V? các ði?m ngang t?o nét ð?t
            // Ði?m (i, y1) ð?n (i, y2)
            if (net < 5) {
                glVertex2i(i, y1);
            }
            net = (net + 1) % 10;
        }

        for (i = y1; i <= y2; i++) {
            // V? các ði?m d?c t?o nét ð?t
            // Ði?m (x1, i) ð?n (x2, i)
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
