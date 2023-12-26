import random

# Cấu trúc dữ liệu biểu diễn gen
class Gene:
    def __init__(self, type, value=None, op=None):
        self.type = type  # Loại gen: số (S), toán tử (O), biến (V)
        self.value = value  # Giá trị của gen (nếu là số hoặc biến)
        self.op = op  # Nếu là toán tử, lưu trữ toán tử (+, -, *, /)

# Hàm tạo một cá thể ngẫu nhiên
def create_random_individual(gene_count):
    individual = []

    for _ in range(gene_count):
        if random.choice([True, False]):
            # 50% khả năng là số
            gene = Gene('S', random.uniform(0, 10))  # Số ngẫu nhiên từ 0 đến 10
        else:
            # 50% khả năng là toán tử hoặc biến
            gene_type = random.choice(['O', 'V'])
            gene = Gene(gene_type, op=random.choice("+-*/") if gene_type == 'O' else 'X')

        individual.append(gene)

    return individual

# Hàm in biểu diễn cá thể thành chuỗi
def individual_to_string(individual):
    expression = ''
    for gene in individual:
        if gene.type == 'S':
            expression += str(gene.value)
        elif gene.type == 'O':
            expression += gene.op
        elif gene.type == 'V':
            expression += 'X'  # Giả sử biến là X
        expression += ' '

    return expression

if __name__ == "__main__":
    # Số lượng gen trong mỗi cá thể
    gene_count = 5

    # Tạo một cá thể ngẫu nhiên
    individual = create_random_individual(gene_count)

    # In biểu diễn của cá thể
    print("Individual:", individual_to_string(individual))
