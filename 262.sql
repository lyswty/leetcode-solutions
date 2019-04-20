# Write your MySQL query statement below
select Trips.Request_at Day, round(count(if(Status!='completed',Status,null))/count(Status),2) as 'Cancellation Rate' from Users,Trips where Users.Users_Id=Trips.Client_Id and Users.Banned!='Yes' and Trips.Request_at>='2013-10-01' and Trips.Request_at<='2013-10-03' group by Trips.Request_at
