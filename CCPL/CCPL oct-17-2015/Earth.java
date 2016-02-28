import java.io.*;
import java.math.*;
import java.util.StringTokenizer;

public class Earth {
    static double R = 6371009.00; 
    static double EPS = 1e-10;
    static double sphericalDistance(double latitudS,double longitudS,double latitudF,double longitudF){
       latitudS = Math.toRadians(latitudS);
       latitudF = Math.toRadians(latitudF);
       longitudS = Math.toRadians(longitudS);
       longitudF = Math.toRadians(longitudF);
    
       double deltaLongitud = longitudF - longitudS;
       double deltaLatitud = latitudF - latitudS;
       double a = Math.pow((Math.sin(deltaLatitud/2)),2) + Math.cos(latitudS) * Math.cos(latitudF) * Math.pow(Math.sin(deltaLongitud/2), 2);
       double c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
       double d = R * c;
       double e = Math.sqrt(2.*R*R *(1-Math.cos(c)));
       return Math.round(d-e+EPS);
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double latitudS, longitudS, latitudF, longitudF;
        String cases, lines;
        cases = br.readLine();
        StringTokenizer st;
        for(int i=0; i<Integer.valueOf(cases); i++){
            lines = br.readLine();
            st = new StringTokenizer(lines);
            latitudS = Double.valueOf(st.nextToken());
            longitudS = Double.valueOf(st.nextToken());
            latitudF = Double.valueOf(st.nextToken());
            longitudF = Double.valueOf(st.nextToken());
            
            double ans1 = sphericalDistance(latitudS, longitudS, latitudF, longitudF);
            
            System.out.println ((long)(0.5 + ans1));
            
        }
        
    }
}
