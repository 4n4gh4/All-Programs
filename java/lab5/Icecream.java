package lab5;

class Icecream {

    public void Quantity(int r, int h) {
        double coneVolume = (1.0 / 3) * Math.PI * r * r * h;
        System.out.printf("%.2f\n", coneVolume);
    }

    public void Quantity(int r) {
        double ballVolume = (4.0 / 3) * Math.PI * r * r * r;
        System.out.printf("%.2f\n", ballVolume);
    }
}
