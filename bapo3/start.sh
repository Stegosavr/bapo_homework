# Apply all configurations
kubectl apply -f nginx-config.yaml
kubectl apply -f secret.yaml
kubectl apply -f deployment.yaml
kubectl apply -f service.yaml
kubectl apply -f ingress.yaml  # Optional

# Check status
kubectl get pods
kubectl get services
kubectl get ingress

# View logs
kubectl logs -l app=ip-app -c ip-container
kubectl logs -l app=ip-app -c nginx-container

# Access the service
kubectl port-forward service/ip-app-service 8080:80
# Then visit http://localhost:8080
