SELECT nonManager.name AS Employee FROM Employee nonManager
WHERE managerId IN
(
  SELECT id FROM Employee manager
  WHERE nonManager.salary > manager.salary
);
