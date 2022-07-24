package program;

import java.io.File;
import java.util.Scanner;
import java.util.Vector;

class Programa {

    public static void main(String[] args) throws Exception {
        System.out.println(createPL(args[0]));
    }

    static String createPL(String input) throws Exception {
        int n = 0;
        double vmin = 0, vmax = 0, vini = 0, k = 0, tmax = 0, ct = 0, ca = 0;
        Vector<Double> d = new Vector<Double>();
        Vector<Double> y = new Vector<Double>();
        String pl = "min:";

        File file = new File(System.getProperty("user.dir") + "\\" + input);
        Scanner s = new Scanner(file);

        n = s.nextInt();

        for (int i = 0; i < n; i++) {
            d.add((double) s.nextDouble());
        }
        for (int i = 0; i < n; i++) {
            y.add((double) s.nextDouble());
        }
        vini = s.nextDouble();
        vmin = s.nextDouble();
        vmax = s.nextDouble();
        k = s.nextDouble();
        tmax = s.nextDouble();
        ct = s.nextDouble();
        ca = s.nextDouble();
        s.close();

        for (int i = 1; i <= n; i++) {
            pl += " + " + ca + "x" + i;
            pl += " + " + ca + "z" + i;
            pl += " + " + ct + "t" + i;
        }
        pl += ";\r\n";
        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += "x" + i + " - z" + i + " = " + y.elementAt(i - 1) + " - h" + i;
            pl += ";\r\n";
        }
        pl += "\r\n";
        pl += "v1" + " = " + vini +" + "+ y.elementAt(0);
        pl += ";\r\n";
        for (int i = 2; i <= n; i++) {
            pl += "v" + i + " = " + "v" + (i - 1) + " + " + y.elementAt(i - 1) + " - h" + (i - 1);
            pl += ";\r\n";
        }
        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += "v" + i + " - h" + i + " <= " + vmax;
            pl += ";\r\n";
        }
        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += "v" + i + " - h" + i + " >= " + vmin;
            pl += ";\r\n";
        }
        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += "h" + i + " <= " + "v" + i;
            pl += ";\r\n";
        }

        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += k + "h" + i + " + " + "t" + i + " >= " + d.elementAt(i - 1);
            pl += ";\r\n";
        }
        pl += "\r\n";
        for (int i = 1; i <= n; i++) {
            pl += "t" + i + " <= " + tmax;
            pl += ";\r\n";
        }
        pl += "\r\n";
        char a[] = { 'x', 'z', 'h', 't' };
        for (char hm : a) {
            for (int i = 1; i <= n; i++) {
                pl += hm + "" + i + " >= 0";                
                pl += ";\r\n";
            }
        }
        return pl;
    }
}
