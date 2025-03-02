class RecentCounter {
    private List<Integer> reqs;

    public RecentCounter() {
        reqs = new ArrayList<>();
    }

    public int ping(int t) {
        int count = 0;
        int lower = t - 3000;
        reqs.add(t);
        int i = reqs.size() - 1;
        
        while (i >= 0 && (reqs.get(i) >= lower || reqs.get(i) >= t)) {
            count++;
            i--;
        }
        return count;
    }
}
