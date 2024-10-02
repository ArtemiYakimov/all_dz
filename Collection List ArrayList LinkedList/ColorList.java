import java.util.ArrayList;

public class ColorList {
    private ArrayList<String> colors;

    public ColorList(){
        colors = new ArrayList<>();
        colors.add("red");
        colors.add("blue");
        colors.add("green");
        colors.add("brown");
    }

    public boolean containsColor(String color) {
        return colors.contains(color);
    }

    public static void main(String[] args) {
        ColorList colorList = new ColorList();
        String colorToSearch = "red";

        if (colorList.containsColor(colorToSearch)) {
            System.out.println(colorToSearch + " is in the list.");
        } else {
            System.out.println(colorToSearch + " is not in the list.");
        }
    }
}
