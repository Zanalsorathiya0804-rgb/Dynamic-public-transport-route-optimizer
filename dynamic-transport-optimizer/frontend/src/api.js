export const fetchRoute = async () => {
  const res = await fetch("http://localhost:3001/api/route");
  return await res.json();
};
