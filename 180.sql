# Write your MySQL query statement below
select distinct l.Num as ConsecutiveNums from Logs l where Num=(select Num from Logs where Id=l.Id+1) and Num=(select Num from Logs where Id=l.Id+2)
