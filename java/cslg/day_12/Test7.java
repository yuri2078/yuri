import java.util.*;

class SortablePoint implements Comparable<SortablePoint> {
  int x;
  int y;

  SortablePoint(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public int compareTo(SortablePoint point) {
    double distance_1 = Math.sqrt(x * x + y * y);
    double distance_2 = Math.sqrt(point.x * point.x + point.y * point.y);
    if (Math.abs(distance_1 - distance_2) < 0.000000001) {
      return x - point.x;
    }
    if (distance_1 - distance_2 > 0) {
      return 1;
    }
    return -1;
  }

  public String toString() {
    return String.format("(%d,%d)", x, y);
  }
}

class CmpByXY implements Comparator<SortablePoint> {

  public int compare(SortablePoint p1, SortablePoint p2) {
    int p_1 = (p1.x * p1.y) % 10;
    int p_2 = (p2.x * p2.y) % 10;
    if (p_1 == p_2) {
      return p2.x - p1.x;
    }
    return p_1 - p_2;
  }
}

public class Test7 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    n = sc.nextInt();
    List<SortablePoint> ps = new ArrayList<SortablePoint>();
    for (int i = 0; i < n; i++) {
      ps.add(new SortablePoint(sc.nextInt(), sc.nextInt()));
    }
    Collections.sort(ps);
    System.out.println(ps);
    Collections.sort(ps, new CmpByXY());
    System.out.println(ps);
    sc.close();
  }
}
