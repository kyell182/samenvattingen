# pytorch cheatsheet

<!-- Tensorbibliotheek voor GPU-acceleratie, autograd en neural networks (tensors, modellen, training) -->
> Tensorbibliotheek voor GPU-acceleratie, autograd en neural networks

```python
import torch
```

## Tensor aanmaken

```python
x = torch.tensor([1, 2, 3])           # Maak tensor van lijst
x = torch.zeros(3, 3)                 # 3x3 matrix met nullen
x = torch.ones(2, 2)                  # 2x2 matrix met enen
x = torch.eye(3)                      # Identiteitsmatrix
x = torch.arange(0, 10, 2)            # Getallen van 0 tot 8 met stap 2
x = torch.linspace(0, 1, 5)           # 5 waarden tussen 0 en 1
x = torch.rand(3, 3)                  # Willekeurige waarden [0, 1)
x = torch.randn(3, 3)                 # Willekeurige waarden ~N(0,1)
x = torch.randint(0, 10, (2, 3))      # Willekeurige ints [0,10)
```

## Tensor info

```python
x.shape                              # Vorm (rows, cols)
x.dtype                              # Datatype
x.device                             # CPU of GPU
x.numel()                            # Aantal elementen
```

## Conversies

```python
x.numpy()                            # Tensor → NumPy array
torch.from_numpy(arr)                # NumPy array → Tensor
x.to(torch.float32)                  # Typeconversie
x.to("cuda")                         # Verplaats naar GPU
x.to("cpu")                          # Terug naar CPU
```

## Element-bewerkingen

```python
torch.add(a, b)                      # Optellen
torch.sub(a, b)                      # Aftrekken
torch.mul(a, b)                      # Vermenigvuldigen
torch.div(a, b)                      # Delen
torch.pow(a, 2)                      # Macht
torch.sqrt(a)                        # Wortel
torch.mean(a)                        # Gemiddelde
torch.sum(a)                         # Som
torch.max(a)                         # Maximum
torch.min(a)                         # Minimum
```

## Matrix-bewerkingen

```python
torch.matmul(a, b)                   # Matrixvermenigvuldiging
a @ b                                # Zelfde als matmul
a.T                                  # Transponeren
torch.inverse(a)                     # Inverse matrix
torch.det(a)                         # Determinant
```

## Indexeren & slicing

```python
x[0]                                 # Eerste rij
x[:, 1]                              # Tweede kolom
x[1, 2]                              # Specifiek element
x[1:3, :]                            # Rijen 1–2
```

## Gradients (autograd)

```python
x = torch.tensor([2.0], requires_grad=True)
y = x ** 2                           # y = x²
y.backward()                         # Bereken dy/dx
x.grad                               # Bekijk gradient
```

## Modeltraining basics

```python
model = torch.nn.Linear(2, 1)        # Lineaire laag: 2 in → 1 uit
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)
loss_fn = torch.nn.MSELoss()
```

## Forward + backward

```python
pred = model(torch.tensor([[1.0, 2.0]]))
loss = loss_fn(pred, torch.tensor([[1.0]]))
loss.backward()
optimizer.step()                     # Update gewichten
optimizer.zero_grad()                # Reset gradients
```

## Opslaan & laden

```python
torch.save(model.state_dict(), "model.pth")   # Opslaan
model.load_state_dict(torch.load("model.pth"))# Laden
```

## GPU-check

```python
torch.cuda.is_available()            # True als CUDA aanwezig is
```
