from functools import total_ordering

int_input = lambda : map(int, input().split())

@total_ordering
class User(object):
    prob_n = 0
    full_scores = []
    def __init__(self, id):
        self.id = id;
        self.show_in_list = False
        self.scores = [-1] * self.prob_n

    def get_total_score(self):
        if hasattr(self, 'total_score'):
            return self.total_score
        total = 0
        for score in self.scores:
            if score != -1:
                total += score
        self.total_score = total
        return total

    def get_perfect_num(self):
        if hasattr(self, 'perfect_num'):
            return self.perfect_num
        count = 0
        for score, full_score in zip(self.scores, self.full_scores):
            if score == full_score:
                count += 1
        self.perfect_num = count
        return count

    def update(self, p_id, score):
        if score != -1:
            self.show_in_list = True
            self.scores[p_id - 1] = max(self.scores[p_id - 1], score)
        elif self.scores[p_id - 1] == -1:
            self.scores[p_id - 1] = 0

    def print_score(self):
        process = lambda n: '-' if n == -1 else str(n)
        print('{:05d} {} '.format(self.id, self.total_score) +
              ' '.join(map(process, self.scores)), end='')

    def __lt__(self, other):
        if self.get_total_score() > other.get_total_score():
            return True
        if self.get_total_score() < other.get_total_score():
            return False
        if self.get_perfect_num() > other.get_perfect_num():
            return True
        if self.get_perfect_num() < other.get_perfect_num():
            return False
        return self.id < other.id

    def __eq__(self, other):
        return self.get_total_score() == other.get_total_score() and self.get_perfect_num() == other.get_perfect_num() and self.id == other.id

user_n, prob_n, sub_n = int_input()
User.prob_n = prob_n
full_scores = int_input()
User.full_scores = list(full_scores)
users = [User(i) for i in range(1, user_n + 1)]
for _ in range(sub_n):
    id, p_id, score = int_input()
    users[id - 1].update(p_id, score)
users.sort()
rank = 1
samerank = 1
rankscore = users[0].total_score
if users[0].show_in_list:
    print(1, '', end='')
    users[0].print_score()
else:
    exit(0)
for user in users[1:]:
    if not user.show_in_list:
        break
    if user.total_score == rankscore:
        samerank += 1
    else:
        rank += samerank
        samerank = 1
        rankscore = user.total_score
    print()
    print(rank, '', end='')
    user.print_score()
