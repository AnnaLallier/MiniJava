class TestReturn {
    public static void main(String[] args) {
        {
            System.out.println(new Returnnnn().maFunction(true));
            System.out.println(new Returnnnn().maFunction(false));
        }
    }
}


class Returnnnn {
    public int maFunction(boolean b) {
        if (true) {
            return 1;
        } else {
            return 2;
        }
    }
}