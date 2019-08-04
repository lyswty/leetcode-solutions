class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        time_list = []
        for time in timePoints:
            cur_time = time.split(':')
            time_list.append(int(cur_time[0]) * 60 + int(cur_time[1]))
        time_list.sort()
        res = min(abs(time_list[0] - time_list[len(time_list) - 1]), 1440 - abs(time_list[0] - time_list[len(time_list) - 1]))
        for i in range(1, len(time_list)):
            res = min(res, abs(time_list[i] - time_list[i - 1]), 1440 - abs(time_list[i] - time_list[i - 1]))
        return res
