class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int Beg_days[] = new int[2];
        int End_days[] = new int[2];

        StringBuilder st = new StringBuilder();
        st.append(arriveAlice.substring(0 , 2));
        int arrAM = giveValue(st);
        st = new StringBuilder(arriveAlice.substring(3 , 5));
        int arrAD = giveValue(st);

        st = new StringBuilder(arriveBob.substring(0 , 2));
        int arrBM = giveValue(st);
        st = new StringBuilder(arriveBob.substring(3 , 5));
        int arrBD = giveValue(st);

        st = new StringBuilder(leaveAlice.substring(0 , 2));
        int leaAM = giveValue(st);
        st = new StringBuilder(leaveAlice.substring(3 , 5));
        int leaAD = giveValue(st);

        st = new StringBuilder(leaveBob.substring(0 , 2));
        int leaBM = giveValue(st);
        st = new StringBuilder(leaveBob.substring(3 , 5));
        int leaBD = giveValue(st);

        // the logic============================//
        Beg_days[0] = Math.max(arrAM , arrBM);
        if(arrAM == arrBM) {
            Beg_days[1] = Math.max(arrAD, arrBD);
        }else if(arrAM > arrBM) {
            Beg_days[1] = arrAD;
        } else Beg_days[1] = arrBD;
        
        End_days[0] = Math.min(leaAM , leaBM);
        if(leaAM == leaBM) {
            End_days[1] = Math.min(leaBD, leaAD);
        }else if(leaAM <= leaBM) {
            End_days[1] = leaAD;
        } else End_days[1] = leaBD;
        //=====================================//

        return totaldays(Beg_days , End_days);
    }

    public int totaldays(int []B , int[]E) {
      int total = 0;
      if(B[0] == E[0] && B[1] > E[1]) return 0;
      if(B[0] > E[0]) return 0;
      if(B[0] == E[0]) {
        total = E[1] - B[1] + 1;
      } else {
        total = days_mon(B[0]) - B[1] + 1;
        for(int i = B[0] + 1 ; i < E[0] ; i++) {
            total += days_mon(i);
        }
        total += E[1];
      }
      return total;
    }

    public int days_mon(int m) {
        int total = 0;
        if(m < 8) {
            if(m % 2 == 0) {
                if(m == 2) total = 28;
                else total = 30; 
            } else total = 31;
        } else {
            if(m % 2 == 0) {
                total = 31; 
            } else total = 30;
        }
        return total;
    }
    
    public int giveValue(StringBuilder st) {
        return Integer.parseInt(st.toString());
    }
}