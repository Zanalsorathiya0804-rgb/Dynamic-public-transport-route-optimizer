import { MapContainer, TileLayer, Marker, Popup, Polyline } from "react-leaflet";
import { useEffect, useState } from "react";
import { fetchRoute } from "./api";

function MapView() {
  const [route, setRoute] = useState([]);

  useEffect(() => {
    fetchRoute().then(data => setRoute(data.route));
  }, []);

  const polyline = route.map(p => [p.lat, p.lon]);

  return (
    <MapContainer center={[19.123, 72.833]} zoom={14} style={{ height: "80vh" }}>
      <TileLayer url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png" />
      {route.map((point, i) => (
        <Marker key={i} position={[point.lat, point.lon]}>
          <Popup>{point.name} ({point.type})</Popup>
        </Marker>
      ))}
      <Polyline positions={polyline} color="blue" />
    </MapContainer>
  );
}

export default MapView;
