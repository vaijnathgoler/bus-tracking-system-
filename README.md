# bus-tracking-system-
basic bus tracking system using C++
import { useState, useEffect } from 'react'
import { MapPin } from 'lucide-react'

interface Bus {
  id: string
  latitude: number
  longitude: number
}

export default function Component() {
  const [buses, setBuses] = useState<Bus[]>([
    { id: 'Bus001', latitude: 40.7128, longitude: -74.0060 },
    { id: 'Bus002', latitude: 34.0522, longitude: -118.2437 },
    { id: 'Bus003', latitude: 51.5074, longitude: -0.1278 },
  ])

  useEffect(() => {
    const interval = setInterval(() => {
      setBuses(prevBuses =>
        prevBuses.map(bus => ({
          ...bus,
          latitude: bus.latitude + (Math.random() - 0.5) * 0.01,
          longitude: bus.longitude + (Math.random() - 0.5) * 0.01,
        }))
      )
    }, 5000)

    return () => clearInterval(interval)
  }, [])

  return (
    <div className="p-4 bg-gray-100 min-h-screen">
      <h1 className="text-2xl font-bold mb-4">Bus Tracking System</h1>
      <div className="bg-white p-4 rounded-lg shadow-md">
        <div className="relative w-full h-[400px] bg-blue-100 rounded-md overflow-hidden">
          {buses.map(bus => (
            <div
              key={bus.id}
              className="absolute"
              style={{
                left: `${(bus.longitude + 180) * (100 / 360)}%`,
                top: `${(90 - bus.latitude) * (100 / 180)}%`,
              }}
            >
              <MapPin className="text-red-500 h-6 w-6" />
              <div className="bg-white px-2 py-1 rounded-md shadow-sm text-xs">
                {bus.id}
              </div>
            </div>
          ))}
        </div>
        <div className="mt-4">
          <h2 className="text-lg font-semibold mb-2">Bus Locations</h2>
          <ul>
            {buses.map(bus => (
              <li key={bus.id} className="mb-2">
                <span className="font-medium">{bus.id}:</span> Latitude: {bus.latitude.toFixed(4)}, Longitude: {bus.longitude.toFixed(4)}
              </li>
            ))}
          </ul>
        </div>
      </div>
    </div>
  )
}
