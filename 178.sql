# Write your MySQL query statement below
select Score,(select count(distinct score)from Scores where score>=s.Score)as Rank from Scores s order by Score desc;
