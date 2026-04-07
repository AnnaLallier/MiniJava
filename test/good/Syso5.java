class Syso5 {
    public static void main(String[] args) {
        // Syso, in MiniJava, prints string[]
        System.out.println(new Fac().computeFac(0));
    }
}
class Fac {
    public int computeFac(int num) {
        String[] s;
        int i;
        s = new String[5];
        i=0;
        while (i < 5) {
            s[i] = "toto";
            i = i + 1;
        }
        System.out.println(s[0]);
        return 0;
    }
}