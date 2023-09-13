def calculate_accuracy(true_labels, predicted_labels):
    """Calculate Accuracy"""
    correct_predictions = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == pred)
    total_predictions = len(true_labels)
    return correct_predictions / total_predictions

def calculate_tpr(true_labels, predicted_labels, positive_class="+"):
    """Calculate True Positive Rate (Sensitivity)"""
    tp = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == positive_class and pred == positive_class)
    fn = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == positive_class and pred != positive_class)
    return tp / (tp + fn) if (tp + fn) > 0 else 0

def calculate_tnr(true_labels, predicted_labels, negative_class="-"):
    """Calculate True Negative Rate (Specificity)"""
    tn = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == negative_class and pred == negative_class)
    fp = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == negative_class and pred != negative_class)
    return tn / (tn + fp) if (tn + fp) > 0 else 0

def calculate_fpr(true_labels, predicted_labels, negative_class="-"):
    """Calculate False Positive Rate"""
    tn = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == negative_class and pred == negative_class)
    fp = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == negative_class and pred != negative_class)
    return fp / (tn + fp) if (tn + fp) > 0 else 0

def calculate_fnr(true_labels, predicted_labels, positive_class="+"):
    """Calculate False Negative Rate"""
    tp = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == positive_class and pred == positive_class)
    fn = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == positive_class and pred != positive_class)
    return fn / (tp + fn) if (tp + fn) > 0 else 0

# True class labels
true_labels = ["+", "+", "-", "-", "-", "+", "-", "+", "-", "+"]
# INPUT
# Predicted class labels based on a threshold (e.g., 0.5)
threshold = 0.5
predicted_labels = ["+" if prob >= threshold else "-" for prob in [0.95, 0.93, 0.87, 0.85, 0.80, 0.78, 0.76, 0.53, 0.43, 0.25]]

accuracy = calculate_accuracy(true_labels, predicted_labels)
tpr = calculate_tpr(true_labels, predicted_labels)
tnr = calculate_tnr(true_labels, predicted_labels)
fpr = calculate_fpr(true_labels, predicted_labels)
fnr = calculate_fnr(true_labels, predicted_labels)

print(f"Accuracy: {accuracy * 100:.2f}%")
print(f"True Positive Rate (TPR): {tpr:.2f}")
print(f"True Negative Rate (TNR): {tnr:.2f}")
print(f"False Positive Rate (FPR): {fpr:.2f}")
print(f"False Negative Rate (FNR): {fnr:.2f}")
