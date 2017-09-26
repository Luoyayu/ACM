import java.io.BufferedInputStream;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;
//题意：给出三个点外接圆，问另外一点是否在圆外
//由三点算出外接圆圆心坐标即可

public class Main
{
    private static Scanner cin;
    public static void main(String[] args) throws IOException
    {
        cin = new Scanner(new BufferedInputStream(System.in));
        int T = cin.nextInt();
        for (int cnt = 1; cnt <= T; cnt++)
        {
            BigDecimal
                    two = new BigDecimal("2.0000"),
                    x1 = cin.nextBigDecimal(), y1 = cin.nextBigDecimal(),
                    x2 = cin.nextBigDecimal(), y2 = cin.nextBigDecimal(),
                    x3 = cin.nextBigDecimal(), y3 = cin.nextBigDecimal(),
                    x  = cin.nextBigDecimal(), y  = cin.nextBigDecimal(),
                    tmp1, tmp2, tmp3, x0, y0;

            tmp1 = (x1.multiply(x1).subtract(x2.multiply(x2)).add(y1.multiply(y1)).subtract(y2.multiply(y2))).multiply(y1.subtract(y3));
            tmp2 = ((x1.multiply(x1).subtract(x3.multiply(x3)).add(y1.multiply(y1)).subtract(y3.multiply(y3))).multiply(y1.subtract(y2)));
            x0 = tmp1.subtract(tmp2);

            tmp3 = (y1.subtract(y3)).multiply(x1.subtract(x2)).multiply(two). subtract((y1.subtract(y2)).multiply(x1.subtract(x3)).multiply(two));

            x0 = x0.divide(tmp3, 10, BigDecimal.ROUND_HALF_EVEN); //设置除法精度防止出现无限循环小数异常

            tmp1 = (x1.multiply(x1).subtract(x2.multiply(x2)).add(y1.multiply(y1)).subtract(y2.multiply(y2))).multiply(x1.subtract(x3));
            tmp2 = ((x1.multiply(x1).subtract(x3.multiply(x3)).add(y1.multiply(y1)).subtract(y3.multiply(y3))).multiply(x1.subtract(x2)));
            y0 = tmp1.subtract(tmp2);

            tmp3 = (y1.subtract(y2)).multiply(x1.subtract(x3)).multiply(two). subtract((y1.subtract(y3)).multiply(x1.subtract(x2)).multiply(two));
            y0 = y0.divide(tmp3, 10, BigDecimal.ROUND_HALF_EVEN);

            BigDecimal dis1,dis2;

            dis1 = (x0.subtract(x1)).multiply(x0.subtract(x1)).add(y0.subtract(y1).multiply(y0.subtract(y1)));
            dis2 = (x0.subtract(x )).multiply(x0.subtract(x )).add(y0.subtract(y ).multiply(y0.subtract(y )));

            //System.out.println(dis1);System.out.println(dis2);

            if(dis1.compareTo(dis2) < 0) // -1 小于;0 等于; 1 大于
                System.out.println("Accepted");
            else
                System.out.println("Rejected");
        }
    }
}