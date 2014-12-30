package algorithms.bitmanipulate; 

import java.util.*; 

public class DrawHorizontalLine {
    /*  Function: Given a bype presented screen, draw a horizon line. 
     *  Solution: Beware of the edge cases. 
     */
    
    public void drawLine(byte[] screen, int width, int x1, int x2, int y) {
        if (screen == null || screen.length == 0 || width <= 0 || (width % 8) != 0) {
            return; 
        }

        int height = screen.length * 8 / width; 

        if (y < 0 || y >= height) {
            return; 
        }

        if (x1 > x2) {
            int tmp = x1; 
            x1 = x2; 
            x2 = tmp; 
        }

        x1 = x1 < 0 ? 0 : x1; 
        x2 = x2 >= width ? width - 1 : x2;

        int offset = y * width / 8; 

        if (x2 - x1 < 8) {
            screen[offset + x1 / 8] = createMask(x1, x2); 
        } else {
            int i = offset + x1 / 8; 
            screen[i++] = createMask(x1 % 8, 7); 

            for (; i < offset + x2 / 8; i++) {
                screen[i] = ~0; 
            }

            screen[i] = createMask(0, x2 % 8); 
        }

        printScreen(screen, width); 
    }

    private static byte createMask(int st, int ed) {
        if (ed - st == 7) {
            return ~0; 
        }

        byte span = (byte) ((1 << (ed - st + 1)) - 1);
        return (byte) (span << (7 - ed)); 
    }

    public static void printScreen(byte[] screen, int width) {
        for (int i = 0; i < screen.length; ++i) {
            printByte(screen[i]); 
            if ((i + 1) * 8 % width == 0) {
                System.out.println(); 
            }
        }
    }

    private static void printByte(byte b) {
        for (int i = 7; i >= 0; i--) {
            System.out.print((b >>> i) & 1); 
        }
    }
}
