import java.util.*;
class shortestpath{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        Map<Integer, List<int[]>> g = new HashMap<>();
        int R=sc.nextInt();
        while(R-->0){
            int a=sc.nextInt();
            int b=sc.nextInt();
            int dist=sc.nextInt();
            if(!g.containsKey(a)){
                g.put(a,new ArrayList<>());
            }
            g.get(a).add(new int[]{b,dist});
            if(!g.containsKey(b)){
                g.put(b,new ArrayList<>());
            }
            g.get(b).add(new int[]{a,dist});
        }
        int st=sc.nextInt();
        int end=sc.nextInt();
        Set<Integer> vis=new HashSet<>();
        PriorityQueue<int[]>pq=new PriorityQueue<>((x,y)->{return x[1]-y[1];});
        pq.add(new int[]{st,0});
        while(!pq.isEmpty()){
            int []curr=pq.poll();
            int currcity=curr[0],currdist=curr[1];
            if(currcity==end){
                System.out.println(currdist);return;
            }
            if(vis.contains(currcity))continue;
            vis.add(currcity);
            if(g.containsKey(currcity)){
                for(int ocarr[]:g.get(currcity)){
                    int oc=ocarr[0],ocd=ocarr[1];
                    if(!vis.contains(oc)){
                        pq.add(new int[]{oc,ocd+currdist});
                    }
                }
            }
        }
    }
}
