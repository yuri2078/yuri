package cslg.day_;

import java.util.Scanner;

class Ball {
    int pos;
    int dx;

    public Ball(int pos) {
        this.pos = pos;
        dx = 1;
    }

    void next() {
        pos = pos + dx;
    }

    boolean isTouch(Ball other) {
        return this.pos == other.pos;
    }

    boolean reachBorder(int L) {
        return pos == L || pos == 0;
    }

    void changeDir() {
        dx = -dx;
    }

    int getPos() {
        return pos;
    }
}

public class test {
    public static void main(String[] args) {
        try (java.util.Scanner in = new Scanner(System.in)) {
            int n, t, l, i, j, k;
            n = in.nextInt();
            l = in.nextInt();
            t = in.nextInt();
            
            Ball b[] = new Ball[n];
            for (i = 0; i < n; i++)
                b[i] = new Ball(in.nextInt());
            i = 0;
            while (i < t) {
                for (j = n - 1; j >= 0; j--) {
                    if (b[j].reachBorder(l))
                        b[j].changeDir();
                    b[j].next();
                    for (k = 0; k < n; k++) {
                        if (k != j && b[j].isTouch(b[k])) {
                            b[j].changeDir();
                            b[k].changeDir();
                            break;
                        }
                    }
                }
                i++;
            }
            for (i = 0; i < n; i++)
                System.out.printf("%d ", b[i].pos);

            in.close();
        }
    }
}