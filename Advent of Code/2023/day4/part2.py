import sys, re, collections

ans, cnt = 0, collections.defaultdict(lambda: 1)
for card in sys.stdin:
    id, card = re.match(r"Card\s+(\d+):\s+(.*)", card).groups()
    id = int(id)
    winning, have = [{int(card) for card in cards.split()} for cards in card.split(" | ")]
    won = winning & have
    ans += cnt[id]
    for next in range(1, len(won) + 1):
        cnt[id + next] += cnt[id]
print(ans)